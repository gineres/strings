#include <iostream>
#include "Tests.h"

void EXPECT_TRUE(bool data){
    if (data){
        std::cout<< " PASSED!" << std::endl;
        return;
    }
    std::cout<< " FAILED: expected 1, got " << data << std::endl;
}

void EXPECT_FALSE(bool data){
    if (!data){
        std::cout<< " PASSED!" << std::endl;
        return;
    }
    std::cout<< " FAILED: expected 0, got " << data << std::endl;
}

void EXPECT_EQ(const char *str1, const char *str2, int size){
    bool isEqual = true;
    for (int i = 0; i < size; i++)
    {
        isEqual = str1[i] == str2[i];
    }
    if(isEqual){
            std::cout<< " PASSED!" << std::endl;
        return;
    }
    std::cout<< " FAILED: expected "<< str1 <<", got " << str2 << std::endl;
}

void EXPECT_EQ(int int1, int int2){
    if (int1 == int2){
        std::cout<< " PASSED!" << std::endl;
        return;
    }
    std::cout<< " FAILED: expected "<<int1<<", got " << int2 << std::endl;
}

void emptyConstructor(){
    String str{};
    std::cout<< "TEST EMPTY_CONSTRUCTOR:";
    EXPECT_EQ(0, str.getSize());
}

void copyConstructorFilled(){
    String str1{"ABC"};
    String str2{str1};
    std::cout<< "TEST COPY_CONSTRUCTOR_FILLED:";
    EXPECT_EQ(str1.getStr(), str2.getStr(), str1.getSize());
}

void copyConstructorEmpty(){
    String str1{};
    String str2{str1};
    std::cout<< "TEST COPY_CONSTRUCTOR_EMPTY:";
    EXPECT_EQ(str1.getStr(), str2.getStr(), str1.getSize());
}

void literalConstructor(){
    String str{"ABC"};
    std::cout<< "TEST LITERAL_CONSTRUCTOR:";
    EXPECT_EQ("ABC", str.getStr(), str.getSize());
}

void getSize(){
    String str{"ABC"};
    std::cout<< "TEST GET_SIZE:";
    EXPECT_EQ(3, str.getSize());
}

void getString(){
    String str{"ABC"};
    std::cout<< "TEST GET_STRING:";
    EXPECT_EQ("ABC", str.getStr(), 3);
}

void compEqual(){
    String str1{"ABC"};
    String str2{"ABC"};
    std::cout<< "TEST COMP_EQUAL:";
    EXPECT_TRUE(str1 == str2);
}

void compDifferent(){
    String str1{"ABC"};
    String str2{"A C"};
    std::cout<< "TEST COMP_DIFF:";
    EXPECT_TRUE(str1 == str2);
}

void compEqualWithFunc(){
    String str1{"ABC"};
    String str2{"ABC"};
    std::cout<< "TEST COMP_EQUAL_WITH_FUNCTION:";
    EXPECT_TRUE(str1.comp(str2));
}

void compDifferentWithFunc(){
    String str1{"ABC"};
    String str2{"A C"};
    std::cout<< "TEST COMP_DIFF_WITH_FUNCTION:";
    EXPECT_TRUE(str1.comp(str2));
}

void trimEmpty(){
    String str{};
    std::cout<< "TEST TRIM_EMPTY:";
    EXPECT_FALSE(str.trim());
}

void trimNothingToTrim(){
    String str{"ABCD E F!@#AXXX"};
    std::cout<< "TEST TRIM_NOTHIN_TO_TRIM (BOOL):";
    EXPECT_TRUE(str.trim());
    std::cout<< "TEST TRIM_NOTHIN_TO_TRIM (STRING):";
    EXPECT_EQ("ABCD E F!@#AXXX", str.getStr(), str.getSize());
}

void trimRight(){
    String str{"ABCD E F!@#AXXX          "};
    std::cout<< "TEST TRIM_RIGHT (BOOL):";
    EXPECT_TRUE(str.trim());
    std::cout<< "TEST TRIM_RIGHT (STRING):";
    EXPECT_EQ("ABCD E F!@#AXXX", str.getStr(), str.getSize());
}

void trimLeft(){
    String str{"         ABCD E F!@#AXXX"};
    std::cout<< "TEST TRIM_LEFT (BOOL):";
    EXPECT_TRUE(str.trim());
    std::cout<< "TEST TRIM_LEFT (STRING):";
    EXPECT_EQ("ABCD E F!@#AXXX", str.getStr(), str.getSize());
}

void trimBothSides(){
    String str{"           ABCD E F!@#AXXX                     "};
    std::cout<< "TEST TRIM_BOTH_SIDES (BOOL):";
    EXPECT_TRUE(str.trim());
    std::cout<< "TEST TRIM_BOTH_SIDES (STRING):";
    EXPECT_EQ("ABCD E F!@#AXXX", str.getStr(), str.getSize());
}

void toUpperEmpty(){
    String str{};
    std::cout<< "TEST TO_UPPER_EMPTY:";
    EXPECT_TRUE(str.toUpper());
}

void toUpperAllLow(){
    String str{"ab a a a!@# a x"};
    str.toUpper();
    std::cout<< "TEST TO_UPPER_ALL_LOW:";
    EXPECT_EQ("AB A A A!@# A X", str.getStr(), str.getSize());
}

void toUpperAllUp(){
    String str{"AB A A A!@# A X"};
    str.toUpper();
    std::cout<< "TEST TO_UPPER_ALL_UP";
    EXPECT_EQ("AB A A A!@# A X", str.getStr(), str.getSize());
}

void toUpperMixed(){
    String str{"ab A a A!@# A x"};
    str.toUpper();
    std::cout<< "TEST TO_UPPER_MIXED:";
    EXPECT_EQ("AB A A A!@# A X", str.getStr(), str.getSize());
}

void toLowerEmpty(){
    String str{};
    std::cout<< "TEST TO_LOWER_EMPTY:";
    EXPECT_TRUE(str.toLower());
}

void toLowerAllLow(){
    String str{"ab a a a!@# a x"};
    str.toLower();
    std::cout<< "TEST TO_LOWER_ALL_LOW:";
    EXPECT_EQ("ab a a a!@# a x", str.getStr(), str.getSize());
}

void toLowerAllUp(){
    String str{"AB A A A!@# A X"};
    str.toLower();
    std::cout<< "TEST TO_LOWER_ALL_UP:";
    EXPECT_EQ("ab a a a!@# a x", str.getStr(), str.getSize());
}

void toLowerMixed(){
    String str{"ab A a A!@# A x"};
    str.toLower();
    std::cout<< "TEST TO_LOWER_MIXED:";
    EXPECT_EQ("ab a a a!@# a x", str.getStr(), str.getSize());
}

void replaceCharNonexistent(){
    String str{"A!B!B!B!C"};
    str.replace('I','Z');
    std::cout << "TEST REPLACE_CHAR_NONEXISTENT";
    EXPECT_EQ("A!B!B!B!C", str.getStr(), str.getSize());
}
void replaceCharAll(){
    String str{"!!!!!!"};
    str.replace('!','Z');
    std::cout << "TEST REPLACE_CHAR_ALL";
    EXPECT_EQ("ZZZZZZ", str.getStr(), str.getSize());
}

void replaceStringNonexistent(){
    String str{"A!B!B!B!C"};
    str.replace("ilha","algo");
    std::cout << "TEST REPLACE_STRING_NONEXISTENT";
    EXPECT_EQ("A!B!B!B!C", str.getStr(), str.getSize());
}

void replaceStringAll(){
    String str{"AAAAAA"};
    str.replace("AAAAAA","1");
    std::cout << "TEST REPLACE_STRING_ALL";
    EXPECT_EQ("1", str.getStr(), str.getSize());
}

void replaceByLesser(){
    String str{"aranha e aranha e aranha e aranha"};
    str.replace("aranha","boi");
    std::cout << "TEST REPLACE_STRING_BY_LESSER";
    EXPECT_EQ("boi e boi e boi e boi", str.getStr(), str.getSize());
}

void replaceByHigher(){
    String str{"boi e boi e boi e boi"};
    str.replace("boi","aranha");
    std::cout << "TEST REPLACE_STRING_BY_HIGHER";
    EXPECT_EQ("aranha e aranha e aranha e aranha", str.getStr(), str.getSize());
}

void appendEmpty(){
    String str{};
    str.append("alo");
    std::cout<< "TEST APPEND_EMPTY:";
    EXPECT_EQ("alo", str.getStr(), str.getSize());
}
void appendCasual(){
    String str{"alo"};
    str.append("alo");
    std::cout<< "TEST APPEND_CASUAL:";
    EXPECT_EQ("aloalo", str.getStr(), str.getSize());
}

void insertCharEmptyOtherPos(){
    String str{};
    std::cout<< "TEST INSERT_CHAR_EMPTY_OTHER_POS:";
    EXPECT_FALSE(str.insert('a', 1));
}

void insertCharEmptyFirstPos(){
    String str{};
    std::cout<< "TEST INSERT_CHAR_EMPTY_FIRST_POS (BOOL):";
    EXPECT_TRUE(str.insert('a', 0));
    std::cout<< "TEST INSERT_CHAR_EMPTY_FIRST_POS (STRING):";
    EXPECT_EQ("a",str.getStr(),1);
}

void insertCharOutOfBound(){
    String str{"ABC"};
    std::cout<< "TEST INSERT_STRING_EMPTY_OTHER_POS:";
    EXPECT_FALSE(str.insert('a', 10));
}

void insertCharCasual(){
    String str{"ABC"};
    std::cout<< "TEST INSERT_CHAR_CASUAL (BOOL):";
    EXPECT_TRUE(str.insert('a', 2));
    std::cout<< "TEST INSERT_CHAR_CASUAL (STRING):";
    EXPECT_EQ("ABaC",str.getStr(),str.getSize());
}

void insertStringEmptyFirstPos(){
    String str{};
    std::cout<< "TEST INSERT_STRING_EMPTY_FIRST_POS (BOOL):";
    EXPECT_TRUE(str.insert("aba", 0));
    std::cout<< "TEST INSERT_STRING_EMPTY_FIRST_POS (STRING):";
    EXPECT_EQ("aba",str.getStr(),str.getSize());
}

void insertStringEmptyOtherPos(){
    String str{};
    std::cout<< "TEST INSERT_STRING_EMPTY_OTHER_POS:";
    EXPECT_FALSE(str.insert("aba", 2));
}

void insertStringOutOfBound(){
    String str{"ABC"};
  std::cout<< "TEST INSERT_STRING_OUT_OF_BOUND:";
    EXPECT_FALSE(str.insert("abc", 9));
}

void insertStringCasual(){
    String str{"ABC"};
    std::cout<< "TEST INSERT_CHAR_EMPTY (BOOL):";
    EXPECT_TRUE(str.insert("abc", 2));
    std::cout<< "TEST INSERT_CHAR_EMPTY (STRING):";
    EXPECT_EQ("ABabcC",str.getStr(),str.getSize());
}

void removeCharEmpty(){
    String str{};
    std::cout<< "TEST REMOVE_CHAR_EMPTY:";
    EXPECT_FALSE(str.remove(0));
}

void removeCharOutOfBound(){
    String str{"aba"};
    std::cout<< "TEST REMOVE_CHAR_OUT_OF_BOUND:";
    EXPECT_FALSE(str.remove(3));
}

void removeCharCasual(){
    String str{"aba"};
    std::cout<< "TEST REMOVE_CHAR_CASUAL:";
    EXPECT_TRUE(str.remove(2));
}

void removeStringEmpty(){
    String str{};
    std::cout<< "TEST REMOVE_STRING_EMPTY:";
    EXPECT_FALSE(str.remove(0,1));
}

void removeStringOutOfBound(){
    String str{"aba"};
    std::cout<< "TEST REMOVE_STRING_OUT_OF_BOUND:";
    EXPECT_FALSE(str.remove(1,3));
}

void removeStringCasual(){
    String str{"aba"};
    std::cout<< "TEST REMOVE_STRING_CASUAL:";
    EXPECT_TRUE(str.remove(0,2));
}

void splitCharNonexistent(){
    String str{"A B C"};
    String* strList = str.split('/');
    std::cout<< "TEST SPLIT_CHAR_NONEXISTENT:";
    EXPECT_TRUE(strList[0] == str);
}

void splitCharCasual(){
    String str{"A B C"};
    String* strList = str.split(' ');
    bool test1 = strList[0].getStr()[0] == 'A';
    bool test2 = strList[1].getStr()[0] == 'B';
    bool test3 = strList[2].getStr()[0] == 'C';
    std::cout<< "TEST SPLIT_CHAR_CASUAL:";
    EXPECT_TRUE(test1&test2&test3);
}

void splitStringNonexistent(){
    String str{"A B C"};
    String* strList = str.split("abo");
    std::cout<< "TEST SPLIT_STRING_NONEXISTENT:";
    EXPECT_TRUE(strList[0] == str);
}

void splitStringCasual(){
    String str{"AabobrinhaBabobrinhaC"};
    String* strList = str.split("abobrinha");
    bool test1 = strList[0].getStr()[0] == 'A';
    bool test2 = strList[1].getStr()[0] == 'B';
    bool test3 = strList[2].getStr()[0] == 'C';
    std::cout<< "TEST SPLIT_STRING_CASUAL:";
    EXPECT_TRUE(test1&test2&test3);
}

void searchCharSuccess(){
    String str{"abababa"};
    std::cout<< "TEST SEARCH_CHAR_SUCCESS:";
    EXPECT_TRUE(str.searchFor('a'));
}

void searchCharFailed(){
    String str{"abababa"};
    std::cout<< "TEST SEARCH_CHAR_FAILED:";
    EXPECT_FALSE(str.searchFor('8'));
}

void searchStringSuccess(){
    String str{"abababa"};
    std::cout<< "TEST SEARCH_STRING_SUCCESS:";
    EXPECT_TRUE(str.searchFor("baba"));
}

void searchStringFailed(){
    String str{"abababa"};
    std::cout<< "TEST SEARCH_STRING_FAILED:";
    EXPECT_FALSE(str.searchFor("BABA"));
}

void prefixFound(){
    String str{"!@#ABABA"};
    std::cout<< "TEST PREFIX_FOUND:";
    EXPECT_TRUE(str.hasPrefix("!@#"));
}

void prefixNonexistent(){
    String str{"!@#ABABA"};
    std::cout<< "TEST PREFIX_NONEXISTENT:";
    EXPECT_FALSE(str.hasPrefix("@#"));
}

void sufixFound(){
    String str{"!@#ABABA"};
    std::cout<< "TEST SUFIX_FOUND:";
    EXPECT_TRUE(str.hasSufix("ABABA"));
}

void sufixNonexistent(){
    String str{"!@#ABABA"};
    std::cout<< "TEST SUFIX_NONEXISTENT:";
    EXPECT_FALSE(str.hasSufix("ababa"));
}

void writeLine(){
    String aux{};
    String str{};
    std::cout << "TEST WRITE_LINE: " << std::endl;
    std::cout << "PLEASE ENTER A STRING: ";
    str.writeln();
    aux.append(str.getStr());
    EXPECT_TRUE(aux == str);
}

void write(){
    String aux{};
    String str{};
    std::cout << "TEST WRITE: " << std::endl;
    std::cout << "PLEASE ENTER A STRING: ";
    std::cin >> str;
    aux.append(str.getStr());
    EXPECT_TRUE(aux == str);
}

void printCorrectly(){
    String str{"PASSED"};
    std::cout << "TEST PRINT_CORRECTLY: " << str << std::endl;
}