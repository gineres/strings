#include "String.h"

//CONSTRUCTORS 
String::String(){
    size = 0;
    string = new char;
}

String::String(const char *string){ 
    calculateSize(string);
    this->string = new char[size];
    for (int i = 0; i < size; i++){
        this->string[i] = string[i];
    }
}

String::String(const String &string){
    size = string.getSize();
    this->string = new char[size];
    char aux;
    for (int i = 0; i < size; i++)
    {
        aux = string.getStr()[i];
        this->string[i] = aux;
    }
}

String::~String(){
}

//PRIVATE METHODS
int String::countCharacters(const char *string){
    int strSize = 0;
    for (int i = 0; string[i] != '\0'; i++){
        strSize = i+1;
    }
    return strSize;
}

int* String::listCharacters(const char condition){
    int strSize = 0;
    for (int i = 0; i < size ; i++){
        if (string[i] == condition)
            strSize++;
    }
    int* list = new int[strSize+3];
    list[0] = strSize;
    list[1] = 1;
    list[strSize+2] = size;
    int k =0;
    for (int i = 0; i < size; i++)
    {
        if (string[i] == condition){
            list[k+2] = i;
            k++;
        }
    }
    return list;
}

void String::calculateSize(const char *string){
    for (int i = 0; string[i] != '\0'; i++){
        size = i+1;
    }
}

void String::calculateSizeAlt(const char *string){
    for (int i = 0; string[i] != ' '; i++){
        size = i+1;
    }
}

int String::search(const char *a){
    int sizeAux = countCharacters(a);
    bool found = true;
    int realFound = -1;
    for (int i = 0; i < size; i++){
        if(string[i] == a[0]){
            for (int j = 1; j < sizeAux; j++){
                if (string[i+j] != a[j]){
                    found = false;
                }
            }
            if (found == false){
                found = true;
            }
            else{
                realFound = i;
            }
        }
    }
    return realFound;
}

//PUBLIC METHODS
//IO
void String::print(){
    for (int i = 0; i < size; i++){
        std::cout << string[i];
    }
}

void String::write(){
    char *temp = new char[1];
    int j = 1;
    char lilTemp;
    std::cin.get(lilTemp);
    temp[0] = lilTemp;
    while(lilTemp != ' ' && lilTemp != '\n'){
        std::cin.get(lilTemp);
        if(lilTemp == ' ' || lilTemp == '\n')
            continue;
        j++;
        temp = (char*)realloc(temp, sizeof(char) * j);
        temp[j-1] = lilTemp;
    }
    size = j;
    string = (char*)realloc(string, sizeof(char) * size);
    for(int i = 0; i < size; i++){
        string[i] = temp[i];
    }
}

void String::writeln(){
    char *temp = new char[1];
    int j = 1;
    char lilTemp;
    std::cin.get(lilTemp);
    temp[0] = lilTemp;
    while(lilTemp != '\n'){
        std::cin.get(lilTemp);
        if(lilTemp == '\n')
            continue;
        j++;
        temp = (char*)realloc(temp, sizeof(char) * j);
        temp[j-1] = lilTemp;
    }
    size = j;
    string = (char*)realloc(string, sizeof(char) * size);
    for(int i = 0; i < size; i++){
        string[i] = temp[i];
    }
}

//Booleans

bool String::comp(const String &string){
    return comp(string.getStr());
}

bool String::comp(const char *string){
    for (int i = 0; string[i] != '\0'; i++){
        if (!string[i] == this->string[i]){
            return false;
        }
    }
    return true;
}

bool String::searchFor(char character){
    for (int i = 0; i < size; i++){
        if(string[i] == character)
            return true;
    }
    return false;
}

bool String::searchFor(const String &string){
    return searchFor(string.getStr());
}

bool String::searchFor(const char *a){
    return search(a) != -1;
}

bool String::hasSufix(const char *sufix){
    int sufixSize = countCharacters(sufix);
    return search(sufix) == size - sufixSize;
}

bool String::hasPrefix(const char *prefix){
    return search(prefix) == 0;
}


//Str manipulation
bool String::trim(){
    if (size == 0){
        return false;
    }
    int i = 0;
    int j = size;
    int k = 0;
    for (i ; string[i] == ' ' && i < size; i++){
        continue;
    }
    for (j ; string[j] == ' ' && j < 0; j--){
        continue;
    }
    for (i; i < j; i++){
        string[k] = string[i];
        k++;
    }
    calculateSizeAlt(string);
    string = (char*) realloc(string, sizeof(char) * size);
    return true;
}

void String::replace(const char a, const char b){
    for (int i = 0; i < size; i++){
        if(string[i] == a){
            string [i] = b;
        }
    }
}

bool String::insert(const char a, int position){
    if (position > size){
        return false;
    }
    String aux{string};
    size++;
    string = (char*) realloc(string, sizeof(char) * size);
    for (int i = position; i < size; i++){
        string[i+1] = aux.getStr()[i];
    }
    string[position] = a;
    return true;
}

bool String::insert(const char *a, int position){
    if (position > size){
        return false;
    }
    int sizeA = countCharacters(a);
    String aux{string};
    size = size + sizeA;
    string = (char*) realloc(string, sizeof(char) * size);
    for (int i = position; i < size; i++){
        string[i+sizeA] = aux.getStr()[i];
    }
    for (int i = 0; i < sizeA; i++){
        string[position+i] = a[i];
    }
    return true;
}

bool String::remove(int position){
    if (position >= size){
        return false;
    }
    for (int i = position; i < size-1; i++){
        string[i] = string[i+1];
    }
    size--;
    string = (char*) realloc(string, sizeof(char) * size);
    return true;
}

bool String::remove(int position, int numChar){
    if ((position + numChar) > size){
        return false;
    }
    for (int i = position; i < size-numChar; i++){
        string[i] = string[i+numChar];
    }
    size = size - numChar;
    string = (char*) realloc(string, sizeof(char) * size);
    return true;
}

void String::replace(const String &a, const String &b){
    replace(a.getStr(), b.getStr());
}

void String::replace(const char *a, const String &b){
    replace(a, b.getStr());
}

void String::replace(const String &a, const char *b){
    replace(a.getStr(), b);
}

bool String::toUpper(){
    for (int i = 0; i < size; i++){
        if (string[i] >= 'a' && string[i] <= 'z') {
                string[i] -= ('a' - 'A');
        }
    }
    return true;
}

bool String::toLower(){
    for (int i = 0; i < size; i++){
        if (string[i] >= 'A' && string[i] <= 'Z') {
                string[i] += ('a' - 'A');
        }
    }
    return true;
}

void String::replace(const char *a, const char *b){
    if (size == 0) return;
    do{
        String aux{string};
        int sizeA = countCharacters(a);
        int sizeB = countCharacters(b);
        int sizeDiff = sizeB-sizeA;
        if (sizeDiff != 0){
            this->string = (char*) realloc(this->string,(size - sizeA + sizeB) * sizeof(char));
            size = size - sizeA + sizeB;
        }
        bool found = true;
        int realFound = search(a);
        if (realFound >= 0){
            int i = realFound;
            int k = 0;
            for (i ; i < sizeB+realFound; i++){
                string[i] = b[k];
                k++;
            }
            for (i ; i<size; i++){
                string[i] = aux.string[i-sizeDiff];
            }
        }
    }
    while(search(a) != -1);
}

void String::append(const char *a){
    int sizeAux = countCharacters(a);
    size = size + sizeAux;
    string = (char*) realloc(string, size * sizeof(char));
    int k = 0;
    for (int i = size-sizeAux; i < size; i++){
        string[i] = a[k];
        k++;
    }
}

void String::append(const char a){
    size++;
    string = (char*) realloc(string, size * sizeof(char));
    int k = 0;
    string[size-1] = a;
}

String* String::split(const char character){
    int* sizeSub = listCharacters(character);
    int delay = 0;
    String* result =  new String[sizeSub[0]];
    if(sizeSub[0] > 0){
        for (int i = 0; i < sizeSub[0]+1; i++){
            int k=0;
            int subSize = sizeSub[i+2] - sizeSub[i+1] + 1;
            char* temp = new char[subSize-delay];
            for (int j = sizeSub[i+1] -1 + delay; j < sizeSub[i+2]; j++)
            {
                temp[k] = string[j];
                k++;
            }
            
            String str{temp};
            str.size = subSize - delay;
            result[i] = str;
            if(i == 0) delay = 2;
            //delete[] temp;
        }
    }
    else{
        String copyString{string};
        result[0] = copyString;
    }
    return result;
}

String* String::split(const char *a){
    replace(a, ",");
    String* str = split(',');
    replace(",", a);
    return str;
}

String* String::split(const String &string){
    replace(string.getStr(), ",");
    String* str = split(',');
    replace(",", string.getStr());
    return str;
}

//OPERATORS
bool String::operator==(const String &string){
    return comp(string);
}

bool String::operator==(const char *string){
    return comp(string);
}

bool String::operator!=(const String &string){
    return !(comp(string));
}

bool String::operator!=(const char *string){
    return !(comp(string));
}