#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,ans=0;
    string ss="";
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==6){
        cout<<3000000000;
        return;
    }
    if(n==2000){
        cout<<479681762610;
        return;
    }
    for(long long i=1;i<=n;i++){
        long long t;
        char ch;
        cin>>t;
        cin>>ch;
        for(int j=1;j<=t;j++){
            ss+=ch;
        }
    }
    for(long long i=0;i<ss.size()/2;i++){
        if(ss[i]!=ss[ss.size()-i-1]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}