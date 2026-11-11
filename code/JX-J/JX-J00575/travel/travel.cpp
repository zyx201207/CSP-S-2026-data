#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int a,b,c,d;
int c1,c2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    a=s1[0],b=s1[1];
    c=s2[0],d=s2[1];
    int ab=(a-48)*10+(b-48);
    int cd=(c-48)*10+(d-48);
    if(c1!=c2){
        cout<<"0000";
    }
    else {
        if(ab!=cd){
            cout<<"1000";
        }
        else{
            if(s1[2]<='C' && s2[2]>'C' || s1[2]>'C' && s2[2]<='C'){
                cout<<"1100";
            }
            else{
                if(s1[2]+1==s2[2] || s2[2]+1==s1[2]){
                    cout<<"1111";
                }
                else cout<<"1110";
            }
        }
    }
    return 0;
}