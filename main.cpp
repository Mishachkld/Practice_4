#include "Blocks/Blocks.hpp"

int main() {
    Controller *controller = new Controller();
    controller->readAllBlocks(3);
    controller->outBlocks();
    return 0;
}
