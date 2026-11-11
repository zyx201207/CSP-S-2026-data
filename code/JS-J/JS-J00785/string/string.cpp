#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[100005];
char c[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll t,ans=0;cin>>t;
    bool f=1;
    string s="#";
    for(int k=1;k<=t;k++){
        cin>>x[k]>>c[k];
        if(k>1&&f==1){
            if(x[k]!=x[k-1]){
                f=0;
            }
        }
    }

    if(f==1){
        for(int i=1;i<=t/2;i++){
            if(c[i]!=c[t-i+1]){
                ans+=x[i];
            }
        }
    }
    else{
        for(int i=1;i<=t;i++){
            for(int j=1;j<=x[i];j++){
                s+=c[i];
            }
        }
        //cout<<s<<endl;
        for(int i=1;i<=(s.size()-1)/2;i++){
            if(s[i]!=s[s.size()-i]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
