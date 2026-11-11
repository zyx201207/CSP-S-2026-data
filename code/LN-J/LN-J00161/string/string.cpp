#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a;
    cin>>n;
    char c;
    char ch[300000]={};
    if(n==1)cout<<0;
    else {
        if(n==2){
            long long a2;char c2;
            cin>>a>>c>>a2>>c2;
            cout<<min(a,a2);
        }else {
            for(int i=0;i<n;i++){
                cin>>a>>ch[i];
            }long long cnt=0;
            for(int i=0;i<(n+1)/2;i++){
                if(ch[i]!=ch[n-i-1])cnt++;
            }cout<<cnt;
        }
    }
    return 0;
}
