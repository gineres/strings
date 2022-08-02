#include "Tests.h"

int main(){
    getSize();
    getString();
    emptyConstructor();
    copyConstructorFilled();
    copyConstructorEmpty();
    literalConstructor();
    compEqual();
    compDifferent();
    compEqualWithFunc();
    compDifferentWithFunc();
    trimEmpty();
    trimNothingToTrim();
    trimRight();
    trimLeft();
    trimBothSides();
    toUpperEmpty();
    toUpperAllLow();
    toUpperAllUp();
    toUpperMixed();
    toLowerEmpty();
    toLowerAllLow();
    toLowerAllUp();
    toLowerMixed();
    searchCharSuccess();
    searchCharFailed();
    searchStringSuccess();
    searchStringFailed();
    prefixFound();
    prefixNonexistent();
    sufixFound();
    sufixNonexistent();
    insertCharEmptyFirstPos();
    insertCharEmptyOtherPos();
    insertCharOutOfBound();
    insertCharCasual();
    insertStringEmptyFirstPos();
    insertStringEmptyOtherPos();
    insertStringOutOfBound();
    insertStringCasual();
    replaceCharNonexistent();
    replaceCharAll();
    replaceStringNonexistent();
    replaceStringAll();
    replaceByHigher();
    replaceByLesser();
    removeCharEmpty();
    removeCharOutOfBound();
    removeCharCasual();
    removeStringEmpty();
    removeStringOutOfBound();
    removeStringCasual();
    appendEmpty();
    appendCasual();
    splitCharNonexistent();
    splitCharCasual();
    splitStringNonexistent();
    splitStringCasual();
    write();
    writeLine();
    printCorrectly();
    return 0;
}