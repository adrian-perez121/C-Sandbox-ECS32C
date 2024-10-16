#include <gtest/gtest.h>
#include <string>
#include "stringexamples.hpp"
#include <fstream>

// Demonstrate opening a file for reading
TEST(FileTest, BasicLoadingGetline)
{
    // This should be equal by the std::string equality, which is
    // what we REALLY want.
    //
    // This is being run in build but the actual file is outside, so
    // we do ../
    std::ifstream input{"../testfile.txt"};
    if (!input.is_open())
    {
        ASSERT_TRUE(false);
    }
    std::string s;
    while (!input.eof())
    {
        // Getline gets the string but EXCLUDES the newline
        getline(input, s);
        std::cout << "getline Got string \"" << s << "\"\n";
    }
}

TEST(FileTest, BasicLoadingGetlineSmartpointer)
{
    // This should be equal by the std::string equality, which is
    // what we REALLY want.
    //
    // This is being run in build but the actual file is outside, so
    // we do ../
    auto input = std::make_shared<std::ifstream>("../testfile.txt");
    if (!input->is_open())
    {
        ASSERT_TRUE(false);
    }
    std::string s;
    while (!input->eof())
    {
        // Getline gets the string but EXCLUDES the newline
        getline(*input, s);
        std::cout << "getline Got string \"" << s << "\"\n";
    }
}


TEST(FileTest, OperatorInTest)
{
    std::ifstream input{"../testfile.txt"};
    if (!input.is_open())
    {
        ASSERT_TRUE(false);
    }
    std::string s;
    while (!input.eof())
    {
        input >> s;
        std::cout << "<< Got string \"" << s << "\"\n";
    }
}

TEST(FileTest, OperatorInBetter)
{
    std::ifstream input{"../testfile.txt"};
    if (!input.is_open())
    {
        ASSERT_TRUE(false);
    }
    std::string s;
    while (!input.eof())
    {
        getline(input, s);
        std::istringstream ibuf(s);
        int i;
        ibuf >> i;
        std::cout << "<< Got integer \"" << i << "\"\n";
    }
}
