// Instrument Tree

#ifndef INSTRUMENTTREE_H
#define INSTRUMENTTREE_H

#include <string>
#include <vector>
#include <iostream>

struct InstrumentNode
{
    std::string name;
    std::string type;
    std::string info;
    InstrumentNode *parent;
    InstrumentNode *leftChild;
    InstrumentNode *rightChild;

    InstrumentNode(){};

    InstrumentNode(std::string in_name, std::string in_type, std::string in_info)
    {
        name = in_name;
        type = in_type;
        info = in_info;
    }

};

class InstrumentTree
{
    public:
        InstrumentTree();
        virtual ~InstrumentTree();
        void printInstrumentInventory();
        void addInstrumentNode(std::string name, std::string type, std::string info);
        void findType(std::string wantedType);
        void addFavorite(std::string name);
        void deleteFavorite(std::string name);
        void printFavorite();
        void findInstrument(std::string name);
        void learnAbtInstrument(std::string name);
        int countInstrumentList();
    protected:
    private:
        void printInstrumentInventory(InstrumentNode * node);
        InstrumentNode* searchInstrumentTree(InstrumentNode * node, std::string name);
        void printType(std::string wantedType);
        int countInstrumentList(InstrumentNode *node);
        InstrumentNode *root;
        std::vector<std::string> favorites;
        std::vector<std::string> brass;
        std::vector<std::string> woodwind;
        std::vector<std::string> percussion;
        std::vector<std::string> other;
};

#endif // INSTRUMENTTREE_H
