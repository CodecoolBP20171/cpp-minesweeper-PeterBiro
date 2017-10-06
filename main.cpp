#include <iostream>

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

        }

    private:
        void fillTable() {
            // step 1 goes here
            char *cellPointer;
            cellPointer = table;
            for(int i = 0; i < height * width; ++i) {
                *cellPointer++ = '.';
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