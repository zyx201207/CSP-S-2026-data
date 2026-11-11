#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[214514],ans;
bool f[214514];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=31;i>=0;i--){
        int c=0;
        for(int j=1;j<=n;j++){
            if(f[j]) continue;
            if((a[j]>>i)&(1LL)) c++;
        }
        if(c>=m){
            ans+=(1LL<<i);
            for(int j=1;j<=n;j++){
                if(f[j]) continue;
                if(!((a[j]>>i)&(1LL))) f[j]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
