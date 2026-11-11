#include<bits/stdc++.h>
using namespace std;
string n,m;
string s1,s2,k,b,s;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);



    cin>>n;
    cin>>s1;
    cin>>m;
    cin>>s2;

    if(m==n){

        cout<<1;
        k=s1.substr(0,2);



        b=s2.substr(0,2);

        if(k==b){
            cout<<1;

            if(s1[2]=='D' && s2[2]=='F' || s1[2]!='D' && s2[2]!='F' &&s1[2]!='F' && s2[2]!='D'){
                cout<<1;
                if(s1[2]==s2[2]-1 && s1[2]!='C'|| s1[2]==s2[2]+1 && s1[2]!='D'){
                    cout<<1;
                }else cout<<0;
            }else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";

    cout<<endl;
    return 0;
}
