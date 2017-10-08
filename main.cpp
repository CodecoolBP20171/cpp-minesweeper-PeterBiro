#include <iostream>
#include <ctime>

namespace {
    class Minesweeper {
    public:
        Minesweeper(const size_t width, const size_t height)
                : width(width), height(height),
                  table(new char[width * height]) {
            fillTable();
        }

        /* In a real implementation there would also be a
         * - copy constructor
         * - assignment operator
         * - move constructor
         * - move assignment operator
         * We will learn about them later
         */

        virtual ~Minesweeper() {
            delete[] table;
        }

        void countNeighbours() {
            // step 2 goes here
            char *cellPointer;

            for (int i = 0; i < height * width; ++i) {
                cellPointer = table + i;
                if ( *cellPointer == '.' ) {
                    int mineCounter = 0;
                    // for (int row = -width; row < width+1; row += width) ??
                    for (int row = -1; row < 2; ++row) {
                        for (int col = -1; col < 2; ++col) {
                            if (cellIsOnTable(i , row, col)) {
                                mineCounter += ( *(cellPointer+row*width+col) == '*' ) ? 1 : 0;
                            }
                        }
                    }
                    *cellPointer = '0' + mineCounter;
                }
            }
        }

        void printTable() const {
            // step 3 goes here
            char *cellPointer;
            cellPointer = table;

            for (int i = 0; i < height * width; ++i) {
                std::cout << *cellPointer++;
                if ((i+1) % width == 0) {
                    std::cout << std::endl;
                } else {
                    std::cout << ' ';
                }
            }
            std::cout << std::endl;
        }

    private:
        bool cellIsOnTable(int i, int row, int col) {
            row *= width;
            return ( (i+row+col >= 0) && (i+row+col < height * width) && (i % width + col >= 0) && (i % width + col < width) );
        }

        void fillTable() {
            // step 1 goes here
            int const MINE_CHANCE = 20; //Chance (in %) if a cell has a mine or not
            char *cellPointer;
            cellPointer = table;
            std::srand(std::time(NULL));
            for(int i = 0; i < height * width; ++i) {
                if (rand() % 100 < MINE_CHANCE) {
                    *cellPointer++ = '*';
                } else {
                    *cellPointer++ = '.';
                }
            }
        }

        const size_t width, height;
        char *table;
    };
}

int main() {
    try {
        Minesweeper ms(10, 10);
        ms.printTable();
        ms.countNeighbours();
        ms.printTable();
    } catch (const std::bad_alloc &e) {
        std::cerr << "Couldn't allocate enough memory for minesweeper table" << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}