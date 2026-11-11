#include<bits/stdc++.h>
using namespace std;
string a,b,x,y,f[21],j[21];
int B,Y,n,p;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>b>>x>>y;
if(a==x){
    cout<<"1";
    B="b"-"0";
    Y="y"-"0";
    for(int i=1;i<=20;i++){
            f[i]=b[i];

        }
        for(int i=1;i<=20;i++){
            j[i]=y[i];

        }
    if(f[1]==j[1]){
        cout<<"1";


            if(f[2]=="F"&&j[2]=="D"||f[2]=="D"&&j[2]=="F"){
            cout<<"11";
        }else{
        if(f[2]=="F"||f[2]=="D"||j[2]=="f"||j[2]=="D"){
            cout<<"00";
        }else{
            cout<<"1";
            if(f[2]=="A"&&j[2]=="B"||j[2]=="B"&&j[2]=="C"){
                cout<<"1";
            }else cout<<"0";
        }
        }


        }else cout<<"000";
}else cout<<"0000";
return 0;
}
