#pragma once
#include "memory_cl.h"

#include <iostream>
#include <fstream>
#include <map>

enum CommandCode {
    ININT = 16,
    OUTINT = 17,
    ADDINT = 11,
    SUBINT = 12,
    MULINT = 13,
    DIVINT = 14,
    MOD = 15,
    INFLOAT = 6,
    OUTFLOAT = 7,
    ADDFLOAT = 1,
    SUBFLOAT = 2,
    MULFLOAT = 3,
    DIVFLOAT = 4,
    ITOF = 30,
    FTOI = 10,
    UNCOND = 9,
    PR = 20,
    PNR = 21,
    PB = 22,
    PM = 23,
    PBR = 24,
    PMR = 25,
    IF = 19,
    SEND = 0,
    END = 31
    // undefined commands: 5, 8, 18, 26, 27, 28, 29
    // enjoy for fantasy
};

class Parser
{
private:
    std::map <std::string, CommandCode> mapCommands = {
            {"ININT",    ININT},
            {"OUTINT", OUTINT},
            {"ADDINT",   ADDINT},
            {"SUBINT",   SUBINT},
            {"MULINT",   MULINT},
            {"DIVINT",   DIVINT},
            {"MOD", MOD},
            {"INFLOAT", INFLOAT},
            {"OUTFLOAT", OUTFLOAT},
            {"ADDFLOAT", ADDFLOAT},
            {"SUBFLOAT",  SUBFLOAT},
            {"MULFLOAT", MULFLOAT},
            {"DIVFLOAT", DIVFLOAT},
            {"ITOF",     ITOF},
            {"FTOI",     FTOI},
            {"UNCOND",   UNCOND},
            {"PR", PR},
            {"PNR", PNR},
            {"PB", PB},
            {"PM", PM},
            {"PBR", PBR},
            {"PMR", PMR},
            {"SEND", SEND},
            {"IF", IF},
            {"END", END}
    };

    int command_check (std::string command, int num);

    static std::string getTokenCell (std::string& token, int num);

public:
    static int stoi (std::string stroka, int origin_system = 2);   // string to integer

    static std::string itos (int value, int length = 32, int new_system = 2);   // integer to string

    void get_punched_card (std::ifstream &fin, Memory* mem_obj);

    static bool number (std::string& s); // true, еслм в строке целое число

    static void cellParser (std::string& s, CommandCode& command, int& op1, int& op2, int& op3);

    static long double stold (std::string s); // string to long double

    static std::string ftos (float number);    // float to string

    static std::string getTokenInt();

    static bool stringCmpGE (std::string s1, std::string s2);   // compare, stringCmpGE("-2", "3") = false
};