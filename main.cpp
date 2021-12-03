#include <iostream>
#include <string>
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

int binToDecimal(const string & binaryString){





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

        cout << endl;

        cout << "TESTS" << endl;
        cout << "START TESTS FROM Q1" << endl;
    string hexOne = "2B";
    cout << (hex2Dec(hexOne));
    cout << endl;
    string hexTwo = "42D";
    cout << (hex2Dec(hexTwo)) << endl;
    string hexThree = "71E";
    cout << (hex2Dec(hexThree));
    cout << endl;
    string hexFour = "89ABF";
    cout << (hex2Dec(hexFour)) << endl << endl;
    string hexFive = "ZZ";
    cout << "Attempting to throw an exception.." << endl;
    cout << (hex2Dec(hexFive)) << endl; //test for exception handling
    cout << "START TESTS FROM Q2 " << endl;


}
catch (exception &x) {
    cout << "exception encountered: " << endl << x.what() << endl;
}
return 0;
}
