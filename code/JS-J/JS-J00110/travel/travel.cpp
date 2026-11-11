#include<bits/stdc++.h>
using namespace std;

ifstream fin("travel.in");
ofstream fout("travel.out");

int main(){
    string a,b,c,d;
    fin>>a>>b>>c>>d;

    string Rx="";
    Rx+=b[0];
    Rx+=b[1];
    char Ry=b[2];
    string Xx="";
    Xx+=d[0];
    Xx+=d[1];
    char Xy=d[2];

    bool ans1=(a==c);
    bool ans2=(Rx==Xx);
    bool ans3=(!(Ry<='C' xor Xy<='C'));
    bool ans4=(abs(int(Ry-Xy))==1);

    bool ans=ans1;
    fout<<ans;
    ans=ans&&ans2;
    fout<<ans;
    ans=ans&&ans3;
    fout<<ans;
    ans=ans&&ans4;
    fout<<ans;
}