#include<bits/stdc++.h>
using namespace std;
string Abox,Bbox,Alo,Blo;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>> Abox >> Alo >> Bbox >> Blo ;
    if(Abox==Bbox){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }

    if(Alo[0]==Blo[0]&&Alo[1]==Blo[1]){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }

    char A=Alo[2];
    char B=Blo[2];
    if(A=='A'||A=='B'||A=='C'){
        if(B=='A'||B=='B'||B=='C'){
            cout<<"1";
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else{
        if(B=='D'||B=='E'){
            cout<<"1";
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    if(A-1==B||A+1==B){
        cout<<"1";
    }
    else cout<<"0";


    return 0;
}