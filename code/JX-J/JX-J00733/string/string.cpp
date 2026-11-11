#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,t=0,ans=0;
    int a[200001]={};
    char b[200001]={};
    char s[1000000]={};
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        for(int j=1;j<=a[i];j++){
            s[i]=b[i];
            t++;
            }
        }
    if(t%2==1)t-=1;
    for(int i=1;i*i<=t;i++){
        if(s[i]!=s[t-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
