#include <bits/stdc++.h>
using namespace std;
int main(){
    fropen("travel.in","r",stdin);
    fropen("travel.out","w",stdout);
    string a1,a2;
    int b1,b2;
    cin>>b1>>a1>>b2>>a2;
    if(b1==b2){cout<<1;
    if(a1[1]>='0'&&a1[1]<='9'&&a1[2]>='0'&&a1[2]<='9'&&a2[1]>='0'&&a2[1]<='9'&&a2[2]>='0'&&a2[2]<='9'&&a1[1]==a2[1]&&a1[2]==a2[2]){
            cout<<1;
            if(((a1[3]=='A'||a1[3]=='B'||a1[3]=='C')&&(a2[3]=='A'||a2[3]=='B'||a2[3]=='C'))||((a1[3]=='D'||a1[3]=='F')&&(a2[3]=='D'||a2[3]=='F'))){
                cout<<1;
                if((a1[3]<'C'&&a2[3]<'C')||(a1[3]>'A'&&a2[3]<'A')||(a1[3]=='D'&&a2[3]=='F')||(a2[3]=='D'&&a1[3]=='F')){
                 cout<<1;

                }
                else  cout<<0;
            }
            else  cout<<0;
        }
        else  cout<<0;
    }
    else cout<<0<<0<<0<<0;
    cout<<1l;



return 0;}
