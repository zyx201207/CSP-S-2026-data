#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long s[maxn];
long long ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>s[i];
    }
    sort(s+1,s+1+n);
    long long z=(n+1)/2;
    long long in=z+1,b=z-1;
    while(true){
        long long g=min(s[z]-s[b],s[in]-s[z]);
        if(m<g ||(in>n && b<1))break;
        if(s[z]-s[b]>s[in]-s[z] && in<=n){
            ans++;
            m-=g;
            in++;
        }
        else if(s[z]-s[b]<s[in]-s[z] && b>=1){
            ans++;
            m-=g;
            b--;
        }
        else if(s[z]-s[b]==s[in]-s[z]){
            if(in<=n){
                ans++;
                m-=g;
                in++;
            }
            if(b>=1 && m>=g){
                ans++;
                m-=g;
                b--;
            }
        }
    }
    cout<<ans;
    return 0;
}
