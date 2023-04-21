//
// Created by Mishach on 21.04.2023.
//
#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <fstream>

#define NUM_OF_BLOCK 3

class Block {
public:
    virtual void poll() {
            throw std::out_of_range("Abobus exception: Override.");
        // Некоторая реализация получения данных, которую вам делать
        // не нужно.
    }


private:
    std::string type = "Device name";

};

class ElectricCounterBlock : public Block {
public:
    ElectricCounterBlock(std::string type) : type(std::move(type)){};
    ~ElectricCounterBlock() = default;

    void poll() override {
        std::cout  <<"ElectricCounterBlock: " << type << std::endl;
    }


private:
    std::string type;
};


class DiscreteSignalBlock : public Block {
public:
    DiscreteSignalBlock(std::string type) : type(std::move(type)){};
    ~DiscreteSignalBlock() = default;

    void poll() override {
        std::cout << "DiscreteSignalBlock: " << type << std::endl;
    }

private:
    std::string type;
};

class HeatingControlBlock : public Block {
public:

    HeatingControlBlock(std::string type) : type(std::move(type)){};
    void poll() override {
        std::cout << "HeatingControlBlock: " << type  << std::endl;
    }

private:
    std::string type;
};

class Controller {
public:
    void outBlocks() {
        for (auto & block: blocks) {
            block->poll();
        }
    }

    void readAllBlocks(int quantity) {
        std::ifstream file;
        file.open(PATH);
        std::string block;
        if (file.is_open())
            while (getline(file, block)) {
                selectBlock(block);
            }
        /*while (getline(file, block) and (quantity != 0)) {
                selectBlock(block);
                quantity--;
            }*/
    }

private:
    std::vector<Block *> blocks;
    std::string PATH = "D:\\Development\\C++Project\\Second semester\\Practice_4\\blocks.txt";
    std::string types[NUM_OF_BLOCK][NUM_OF_BLOCK] = {{"Merkuri 230","Nev МТ314","Energomera CE308" },
                                                     {"Reallab NL-16HV", "PriborElectro PRE-16", "Energoservice ENMV-1-24"},
                                                     {"Ouman S203", "Oven TPM232"}};

    void selectBlock(const std::string &block) {  // нужно по нормальному сделать ч-за массивы
        for (int i = 0; i < 3; i++) {
            for (const std::string& item:types[i]) {
                if(item == block and (i == 0))
                    blocks.push_back(new ElectricCounterBlock(block));
                else if((item == block) and (i == 1))
                    blocks.push_back(new DiscreteSignalBlock(block));
                else if((item == block) and (i == 2))
                    blocks.push_back(new HeatingControlBlock(block));
            }
        }
        /*if ((block == "Merkuri 230") or (block == "Nev МТ314") or (block == "Energomera CE308"))
            blocks.push_back(new ElectricCounterBlock(block));
        else if ((block == "Reallab NL-16HV") or (block == "PriborElectro PRE-16") or
                 (block == "Energoservice ENMV-1-24"))
            blocks.push_back(new DiscreteSignalBlock(block));
        else if ((block == "Ouman S203") or (block == "Oven TPM232"))
            blocks.push_back(new HeatingControlBlock(block));*/
    }
};
