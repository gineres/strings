#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <stdlib.h>
#include <malloc.h>

class String {
  
    public:
        //Constructors
        String(); //Construtor vazio
        String(const char *string);
        String(const String &string); //Construtor cópia
        ~String(); //Destrutor

        //Getters
        int getSize() const {
            return size;
        }
        char* getStr() const{
            return string;
        }

        //Methods
        //IO
        void write();
        void writeln();
        void print();

        //Booleans
        bool searchFor(char character);
        bool searchFor(const String &string);
        bool searchFor(const char *a);
        bool comp(const String &string); //PRECISA COMPARAR >= ?
        bool comp(const char *string);
        bool hasSufix(const char *sufix);
        bool hasPrefix(const char *prefix);

        //String manipulation
        bool trim();
        bool toUpper();
        bool toLower();
        void replace(const char a, const char b);
        void replace(const char* a, const char*b);
        void replace(const char *a, const String &b);
        void replace(const String &a, const char *b);
        void replace(const String &a, const String &b);
        void append(const char *a);
        void append(const char a);
        bool insert(const char a, int position);
        bool insert(const char *a, int position);
        bool remove(int position);
        bool remove(int position, int numChar);
        String* split(const char character);
        String* split(const char *a);
        String* split(const String &a);

        //Operators
        //Comparison operators
        bool operator == (const String &string);
        bool operator == (const char *string);
        bool operator !=(const String &string);
        bool operator !=(const char *string);

        //IO operators
        friend std::ostream &operator<<(std::ostream &output,const String &string){
            for (int i = 0; i < string.getSize(); i++){
                output << string.getStr()[i];
            }
            return output;
        }

        friend std::istream &operator>>(std::istream &input, String &string){
            char *temp = new char[1];
            int j = 1;
            char lilTemp;
            input.get(lilTemp);
            temp[0] = lilTemp;
            while(lilTemp != ' ' && lilTemp != '\n'){
                input.get(lilTemp);
                if(lilTemp == ' ' || lilTemp == '\n')
                    continue;
                j++;
                temp = (char*)realloc(temp, sizeof(char) * j);
                temp[j-1] = lilTemp;
            }
            string.size = j;
            string.string = (char*)realloc(string.string, sizeof(char) * string.getSize());
            for(int i = 0; i < string.size; i++){
                string.string[i] = temp[i];
            }
            return input;
        }

    private:
        //Variables
        int size;
        char *string;

        //Methods
        int countCharacters(const char *string);
        int* listCharacters(const char condition);
        void calculateSize(const char *string);
        void calculateSizeAlt(const char *string);
        int search(const char *a);
};

#endif