#include<bits/stdc++.h>
using namespace std;
int n,m,o;char a[5],b[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>a>>m>>b;
    if(n==m){
        if(a[0]==b[0]&&a[1]==b[1]){
            if(a[2]=='D'||a[2]=='F'){
                if(b[2]=='D'||b[2]=='F')cout<<1111;
            }
            else if((a[2]=='C'||a[2]=='A'||a[2]=='B')&&(b[2]=='C'||b[2]=='A'||b[2]=='B')){
                if(a[2]=='B'||b[2]=='B')cout<<1111;
                else cout<<1110;
            }
            else cout<<1100;
        }
        else cout<<1000;
    }
    else cout<<0000;
    return 0;
}
