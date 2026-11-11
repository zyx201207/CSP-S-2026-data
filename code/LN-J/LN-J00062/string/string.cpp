#include<bits/stdc++.h>
using namespace std;
string b,m,y=0;
char a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int x,n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>a;
        for(int j=0;j<x;j++){
            b=b+a;
        }
    }
    for(int i=b.size()-1;i>=0;i--){
        y=y+b[i];
        if(y==b){
            cout<<cnt;
            break;
        }
            }



return 0;
}

