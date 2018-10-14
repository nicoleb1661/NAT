#include <iostream>
#include "NAT.hpp"

int main() {
    std::ifstream natFile;
    std::ifstream flowFile;
    std::ofstream outFile;
    NAT myNat;
    
    //std::cout << "Opening NAT file..." << std::endl;
    natFile.open("NAT.txt");
    if(natFile.is_open())
    {
        myNat.readNat(natFile);
        natFile.close();
    }
    else
    {
        std::cout << "Error opening file" << std::endl;
    }
    
    //std::cout << "Opening FLOW file..." << std::endl;
    flowFile.open("FLOW.txt");
    if(flowFile.is_open())
    {
        myNat.readFlow(flowFile);
        flowFile.close();
    }
    else
    {
        std::cout << "Error opening file" << std::endl;
    }
    
    //myNat.searchNat(); 
    
    outFile.open("OUTPUT.txt");
    if(outFile.is_open())
    {
        myNat.writeOutput(outFile);
        flowFile.close();
    }
    else
    {
        std::cout << "Error opening file" << std::endl;
    }
    
    return 0;
}
