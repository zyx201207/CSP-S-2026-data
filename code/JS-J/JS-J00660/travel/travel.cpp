#include <bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
char e,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>a>>b>>c>>d;
    e=b[2],f=d[2];
    if(a==c){
        cout<<'1';
        if(b[0]==d[0] and b[1]==d[1]){
            cout<<'1';
            if((e=='A' and f=='B')or(e=='A' and f=='C')or(e=='B' and f=='C')or(f=='A' and e=='B')or(f=='A' and e=='C')or(f=='B' and e=='C')or(e=='E' and f=='F')or(e=='F' and f=='E')){
                cout<<'1';
                if((e=='A' and f=='B')or(e=='B' and f=='C')or(f=='A' and e=='B')or(f=='B' and e=='C')or(e=='E' and f=='F')or(e=='F' and f=='E')){
                    cout<<'1';
                }
                else{
                    cout<<'0';
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
}
//100pts