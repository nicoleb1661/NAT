#include "NAT.hpp"

//Read NAT file and store it in NAT table
void NAT::readNat(std::ifstream& file)
{
    std::string key;
    std::string value;
    
    while(getline(file, key, ',')){
        getline(file, value);
        //std::cout << key << " " << value << std::endl;
        if(validateNat(key, value))
        {
            nat_table_.insert(std::pair<std::string, std::string>(key, value));
        }
    }
}

//Read FLOW file and store it in flow vector
void NAT::readFlow(std::ifstream& file)
{
    std::string flow;
    while(getline(file, flow)){
        //std::cout << flow << std::endl;
        if(validateFlow(flow))
        {
            flow_.push_back(flow); 
        }
    }
}

//Search NAT table for existing flow
void NAT::searchNat()
{
    for(std::vector<std::string>::iterator it = flow_.begin(); it != flow_.end(); ++it)
    {
        //std::cout << *it << std::endl;
        std::string temp = *it;
        std::string ip;
        std::string port;
        std::string notFound = "No NAT match for";
        
        port = temp.substr(temp.find(":") + 1);
        ip = temp.erase(temp.find(":"));
        
        std::string s1 = "*:" + port;
        std::string s2 = ip + ":*";
        //std::cout << s1 << " " << s2 << std::endl;
        
        //check for <ip>:<port>
        std::map<std::string,std::string>::iterator j = nat_table_.find(*it);
        if(j != nat_table_.end())
        {
            result_.insert(std::pair<std::string, std::string>(*it, j->second));
        }
        
        //check for *:<port>
        j = nat_table_.find(s1);
        if(j != nat_table_.end())
        {
            result_.insert(std::pair<std::string, std::string>(*it, j->second));
        }

        //check for <ip>:*
        j = nat_table_.find(s2);
        if(j != nat_table_.end())
        {
            result_.insert(std::pair<std::string, std::string>(*it, j->second));
        }
        else
        {
            result_.insert(std::pair<std::string, std::string>(notFound, *it));
        }
    }
}

//Write translation to OUTPUT file
void NAT::writeOutput(std::ofstream& file)
{
    searchNat();
    
    std::map<std::string, std::string>::iterator it;
    for(it = result_.begin(); it != result_.end(); ++it)
    {
        file << it->first;
        file << " -> ";
        file << it->second;
        file << std::endl;
    }
}

//Returns true if NAT is proper format
bool NAT::validateNat(std::string key, std::string value)
{
    bool valid = false;
    bool badKey = false;
    std::string ip;
    std::string port;
    
    /*Parsing the string was inspired by https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c*/
    port = key.substr(key.find(":") + 1);
    ip = key.erase(key.find(":") );
    
    //Check for * in BOTH <ip>:<port> for first pair
    if((ip.find("*") != std::string::npos) && (port.find("*") != std::string::npos))
    {
        badKey = true;
    }
    //Check for * in second <ip>:<port> pair
    if((value.find("*") == std::string::npos) && (!badKey))
    {
        valid = true;
    }
    else
    {
        valid = false;
    }
    
    return valid; 
}

//Returns true if flow is proper format
bool NAT::validateFlow(std::string flow)
{
    if(flow.find("*") != std::string::npos)
    {
        return false;
    }
    else{
        return true;
    }
}

