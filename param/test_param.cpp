#include "BFT_Param.h"

#include <iostream>
#include <string>
using namespace std;

int main(){

    int a, c;
    float b;
    a = 99;
    b = 0;
    c = 66;

    string * str = new string("afasfdasdfasdf");
    string  * h;

    bool bRet;

    CBFT_Param param(str);
    bRet = param.getParam(h);
    cout<<"b: "<<*h<<endl;
    cout<<"b valid: "<<bRet<<endl;
    cout<<"------------------------------ "<<endl;

    CBFT_Param param2( h );
    string * strret;
    bRet = param2.getParam(strret);
    cout<<"strret: "<<*strret<<endl;
    cout<<"strret valid: "<<bRet<<endl;

    delete str;
    str = 0; 

    return 0;
}
