
/*

    tparse.h 1.1

     + Added tryLongParse
     + Added tryLLongParse
     + Added tryLongParseU
     + Added tryLLongParseU
     - Fixed empty strings being accepted into functions resulting in program termination due to std::invalid_argument
     - Fixed strings with negative numbers being allowed to go a step ahead into ex::tryIntParseU function
     - Implemented thing that could possibly prevent ex::tryIntParseU from overflowing given unsigned int var
     - Removed #include <string> due to being useless
    
     To be added:

     - isParsable functions to added data types

    © Seamus Smith 2020

*/

namespace tparse
{
    bool tryIntParse(const std::string str, int& output) // string to parse, output variable (int)
    {
        bool findNum = str.find_first_not_of("-0123456789") == std::string::npos; // only allow these characters in the string to parse
        if (findNum)
        {
            try
            {
                output = std::stoi(str);
                return true;
            }
            catch(const std::out_of_range& e)
            {
                return false;
            }
            catch(const std::invalid_argument& e)
            {
                return false;
            }
        }
        else
            return false;
    }

    bool tryLongParse(const std::string str, long& output) // string to parse, output variable (long)
    {
        bool findNum = str.find_first_not_of("-0123456789") == std::string::npos; // only allow these characters in the string to parse
        if (findNum)
        {
            try
            {
                output = std::stol(str);
                return true;
            }
            catch(const std::out_of_range& e)
            {
                return false;
            }
            catch(const std::invalid_argument& e)
            {
                return false;
            }
        }
        else
            return false;
    }

    bool tryLongParseU(const std::string str, unsigned long& output) // string to parse, output variable (unsigned long)
    {
        bool findNum = str.find_first_not_of("0123456789") == std::string::npos; // only allow these characters in the string to parse
        if (findNum)
        {
            try
            {
                output = std::stoul(str);
                return true;
            }
            catch(const std::out_of_range& e)
            {
                return false;
            }
            catch(const std::invalid_argument& e)
            {
                return false;
            }
        }
        else
            return false;
    }

    bool tryLLongParse(const std::string str, long long& output) // string to parse, output variable (long long)
    {
        bool findNum = str.find_first_not_of("-0123456789") == std::string::npos; // only allow these characters in the string to parse
        if (findNum)
        {
            try
            {
                output = std::stol(str);
                return true;
            }
            catch(const std::out_of_range& e)
            {
                return false;
            }
            catch(const std::invalid_argument& e)
            {
                return false;
            }
        }
        else
            return false;
    }

    bool tryLLongParseU(const std::string str, unsigned long long& output) // string to parse, output variable (unsigned long long)
    {
        bool findNum = str.find_first_not_of("0123456789") == std::string::npos; // only allow these characters in the string to parse
        if (findNum)
        {
            try
            {
                output = std::stoul(str);
                return true;
            }
            catch(const std::out_of_range& e)
            {
                return false;
            }
            catch(const std::invalid_argument& e)
            {
                return false;
            }
        }
        else
            return false;
    }

    bool tryDoubleParse(const std::string str, double& output) // string to parse, output variable (double)
    {
        bool findNum = str.find_first_not_of("-.0123456789") == std::string::npos; // only allow these characters in the string to parse
        if (findNum)
        {
            try
            {
                output = std::stod(str);
                return true;
            }
            catch(const std::out_of_range& e)
            {
                return false;
            }
            catch(const std::invalid_argument& e)
            {
                return false;
            }
        }
        else
            return false;
    }

    bool tryFloatParse(const std::string str, float& output) // string to parse, output variable (float)
    {
        bool findNum = str.find_first_not_of("-.0123456789") == std::string::npos; // only allow these characters in the string to parse
        if (findNum)
        {
            try
            {
                output = std::stof(str);
                return true;
            }
            catch(const std::out_of_range& e)
            {
                return false;
            }
            catch(const std::invalid_argument& e)
            {
                return false;
            }
        }
        else
            return false;
    }

    bool isIntParsable(const std::string str) // string to parse
    {
        bool firstTest = str.find_first_not_of("-0123456789") == std::string::npos;
        int secondTest;
        if (firstTest)
        {
            try
            {
                secondTest = std::stoi(str);
                return true;
            }
            catch(const std::out_of_range& e)
            {
                return false;
            }
            catch(const std::invalid_argument& e)
            {
                return false;
            }
        }
        else
            return false;
    }

    bool isDoubleParsable(const std::string str) // string to parse
    {
        bool firstTest = str.find_first_not_of("-.0123456789") == std::string::npos;
        double secondTest;
        if (firstTest)
        {
            try
            {
                secondTest = std::stod(str);
                return true;
            }
            catch(const std::out_of_range& e)
            {
                return false;
            }
            catch(const std::invalid_argument& e)
            {
                return false;
            }
        }
        else
            return false;
    }
    
    bool isFloatParsable(const std::string str) // string to parse
    {
        bool firstTest = str.find_first_not_of("-.0123456789") == std::string::npos;
        float secondTest;
        if (firstTest)
        {
            try
            {
                secondTest = std::stof(str);
                return true;
            }
            catch(const std::out_of_range& e)
            {
                return false;
            }
            catch(const std::invalid_argument& e)
            {
                return false;
            }
        }
        else
            return false;
    }

    // Below is a namespace for experimental functions. These may not work as intended.
    namespace ex
    { 
        // ! Below function converts string to unsigned long making this function prone to overflowing unsigned ints.
        bool tryIntParseU(const std::string str, unsigned int& output) // string to parse, output variable (unsigned int)
        {
            bool findNum = str.find_first_not_of("0123456789") == std::string::npos; // only allow these characters in the string to parse
            unsigned long testLong;
            if (findNum)
            {
                try
                {
                    testLong = std::stoul(str); // ! This converts the string to an unsigned long.
                }
                catch(const std::out_of_range& e)
                {
                    return false;
                }
                catch(const std::invalid_argument& e)
                {
                    return false;
                }
                if (testLong > 4294967295) // ? Maybe this will prevent the unsigned int variable from overflowing
                    return false;
                else
                {
                    output = testLong;
                    return true;
                }
                    
            }
            else
                return false;
        }
    }
}
