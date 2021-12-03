#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int hex2Dec(string const& hexV);
int binToDecimal(const string & binaryString);


//creating function to convert hex to dec
int hex2Dec(string const& hexV){
    int length = hexV.size(); //initialize length to size of hexV
    int baseNum = 1; // initialize base number to one
    int decV = 0; // initialize decimal value to zero for to be passed to

    for (int i = length -1; i >= 0; i--){ //range from start of length to end extract digits from right to left
        if (hexV[i] >= '0' && hexV[i] <= '9'){ //if to check whether there is a character going from 0 - 9
            decV += (int(hexV[i]) - 48) * baseNum; /*if so subtract 48 from element value (as 48 is assigned to 0, 49 to 1, 50 to 2, etc)
then multiply with the power, and add to decV */
            baseNum = (baseNum * 16); //increments the base by power of 16 since its a hex number to dec
        }
        else if (hexV[i] >= 'A' && hexV[i] <= 'F'){ //else if character is going from A to F
            decV += (int(hexV[i]) - 55) * baseNum; // subtract 55 from el val, multiply by base and sum to decV
            baseNum = (baseNum * 16); //increment base by power of 16
        }
        else
            throw invalid_argument("Bad Entry");
    }
    return decV ;
}
//func shortens string from left to right until you have one number left in the first position then return that num
int binToDecimal(const string & binaryString) {
    if (binaryString.size() == 1) {
        return binaryString[0] - '0'; //return first and only element in str
    }
    //get coefficient (1 or 0), multiply by 2 to the power of the position
    int coEff = binaryString[0] - '0';
    int unFound = coEff * pow(2, (binaryString.size() - 1));

    return unFound + binToDecimal(binaryString.substr(1));
}
//main function tests

int main(){
    try{
    string userHex;
        cout << "Enter your hexadecimal value " << endl;
        cin >> userHex;
        cout << userHex << " converted to dec is: " << endl;
        int convertedVal = hex2Dec(userHex);
        cout << convertedVal << endl;

    string userBinary;
    cout << "Enter binary number " << endl;
    cin >> userBinary;
    cout << userBinary << " converted to dec is.. " << endl;
    int convertedBin = binToDecimal(userBinary);
    cout << convertedBin << endl;
        cout << endl;

    string hexFive = "ZZ";
    cout << "Attempting to throw an exception.." << endl;
    cout << (hex2Dec(hexFive)) << endl; //test for exception handling



}
catch (exception &x) {
    cout << "exception encountered: " << endl << x.what() << endl;
}
return 0;
}
