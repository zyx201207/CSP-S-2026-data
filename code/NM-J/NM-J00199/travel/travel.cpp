#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check1(char x,char y){
    if(x=='A'&&(y=='B'||y=='C')) return 1;
    if(x=='B'&&(y=='A'||y=='C')) return 1;
    if(x=='C'&&(y=='A'||y=='B')) return 1;
    if(x=='D'&&y=='F') return 1;
    if(x=='F'&&y=='D') return 1;
    return 0;
}
bool check2(char x,char y){
    if(x=='A'&&y=='B') return 1;
    if(x=='B'&&(y=='A'||y=='C')) return 1;
    if(x=='C'&&y=='B') return 1;
    if(x=='D'&&y=='F') return 1;
    if(x=='F'&&y=='D') return 1;
    return 0;
}
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;

    string r1=s1.substr(0,1),r2=s2.substr(0,1);
    char l1=s1[2],l2=s2[2];

    if(c1==c2){
        cout<<'1';
        if(r1==r2){
            cout<<'1';
            if(check1(l1,l2)){
                cout<<1;
                if(check2(l1,l2)){
                    cout<<'1';
                }
                else cout<<'0';
            }
            else cout<<'0'<<'0';
        }
        else cout<<'0'<<'0'<<'0';
    }
    else cout<<'0'<<'0'<<'0'<<'0';
    return 0;
}
