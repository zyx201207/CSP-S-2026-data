#include<bits/stdc++.h>
#define int long long
using namespace std;
string m,n,n1,m1;

signed main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
    cin>>n1>>n>>m1>>m;
     for(int i=0;i<=1;i++){
        if(n1[i]!=m1[i]){

        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
        }

     }
    for(int i=0;i<=1;i++){
        if(n[i]!=m[i]){

        cout<<1000;
        return 0;
        }
     }
     if(n[2]=='D'&&m[2]!='F'||n[2]=='F'&&m[2]!='D'||m[2]=='D'&&n[2]!='F'||m[2]=='F'&&n[2]!='D'){

        cout<<1100;
        return 0;
     }
     if(n[2]=='D'&&m[2]=='F'||m[2]=='D'&&n[2]=='D'){
        cout<<1100;
        return 0;
     }
     else {
        if(n[2]=='A'&&m[2]=='C'||m[2]=='A'&&n[2]=='C'){
                cout<<1110;
                return 0;
        }
     }
     cout<<1111;
   return 0;
}
