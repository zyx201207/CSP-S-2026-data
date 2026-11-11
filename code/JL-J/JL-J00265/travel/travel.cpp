#include<bits/stdc++.h>

using namespace std;




int main(){
    freopen("travel.in","s",stdin);
    freopen("travel.out","w",stdout);
    string s;
    string x;
    string c;
    string y;
    int cnt=0,num=0,sn=0,um=0;

    cin>>y>>s>>c>>x;

    int a=x[1],b=s[1];
    char e= x[2],d=s[2];

    if(c==y){
       cnt=1;
       if(a==b){

            num=1;


            if(e<='C'&&d<='C'){
                sn=1;
            }
            else if(e<='F'&&d<='F'){
                sn=1;
            }
            if(abs(e-d)==1){

                um=1;


            }
       }

    }




    cout<<cnt<<num<<sn<<um;
    return 0;
}
