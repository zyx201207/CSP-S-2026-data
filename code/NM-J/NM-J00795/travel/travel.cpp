#include<bits/stdc++.h>
using namespace std;
string n,m;
int a,b;
string sum;
int main(){
    freopen("travle.in","r",stdin);
    freopen("travle.out","w",stdout);
    cin>>a>>n;
    cin>>b>>m;
    if(a==b) sum+="1";
    else {cout<<"0000";return 0;}
    if(n[0]==m[0]&&n[1]==m[1]) sum+="2";
    else {cout<<"1000";return 0;}
    if(n[0]==m[0]&&n[1]==m[1]){
        if(n[2]>='A'&&n[2]<='C'){
            if(m[2]>='D'&&m[2]<='F'){
                cout<<"1100";
                return 0;
            }
        }
        if(m[2]>='A'&&m[2]<='C'){
            if(n[2]>='D'&&n[2]<='F'){
                cout<<"1100";
                return 0;
            }
        }
    }
    else {sum+="3";}
    if(n[2]+1==m[2]||m[2]+1==n[2]) cout<<"1111";
    else {cout<<"1110";return 0;}
    return 0;
}
