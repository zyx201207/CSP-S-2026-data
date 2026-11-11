#include<bits/stdc++.h>
using namespace std;
long long n,m,a,x=0,gao=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a!=x){
            cout<<gao;
        }
        x=a;
        gao++;
    }
