#include<bits/stdc++.h>
using namespace std;
struct travel{
    std::string R_POS;
    std::string X_POS;
};
struct POS{
    std::string id;
    std::string _ABCDEF;
};
std::vector<std::string> ls1={"A","B","C"};
std::vector<std::string> ls2={"D","F"};
bool is_one(std::string a,std::string b){
    if((a=="A"||a=="B"||a=="C")&&(b=="A"||b=="B"||b=="C"))return true;
    if((a=="D"||a=="F")&&(b=="D"||b=="F"))return true;
    return false;
}
int main(){
    fstream read;
    read.open("travel.in",ios_base::in);
    std::string X_POS,R_POS,X_ID,R_ID,X_P,R_P,_X,_R;
    read>>R_POS>>_R>>X_POS>>_X;
    R_ID=_R[0]+_R[1];R_P=_R[2];
    X_ID=_X[0]+_X[1];X_P=_X[2];
    std::string write="0000";
    write[0]=X_POS==R_POS?'1':'0';
    if(write[0]=='0')goto end;
    write[1]=X_ID==R_ID?'1':'0';
    if(write[1]=='0')goto end;
    write[2]=is_one(X_P,R_P)?'1':'0';
    if(write[2]=='0')goto end;
    write[3]=X_P.c_str()[0]-R_P.c_str()[0]==1||R_P.c_str()[0]-X_P.c_str()[0]==1?'1':'0';
    end:
    fstream _write;
    _write.open("travel.out",ios_base::out);
    _write<<write;
    _write.flush();
    return 0;
}