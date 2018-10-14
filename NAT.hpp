#pragma once

#include <fstream>
#include <map>
#include <vector>
#include <iostream>

class NAT{
public:
    void readNat(std::ifstream& file);
    void readFlow(std::ifstream& file);
    void searchNat();
    void writeOutput(std::ofstream& file);
    bool validateNat(std::string key, std::string value);
    bool validateFlow(std::string flow);
    
private:
    std::map<std::string, std::string> nat_table_;
    std::vector<std::string> flow_;
    std::map<std::string, std::string> result_;
};
