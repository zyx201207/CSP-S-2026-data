#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
int n,m,a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0;
    for(int u=30;u>=0;u--){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if((a[i]>>u)&1)cnt++;
        }
        if(cnt>=m){
            ans+=(1<<u);
            for(int i=1;i<=n;i++){
                if(!((a[i]>>u)&1))a[i]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}