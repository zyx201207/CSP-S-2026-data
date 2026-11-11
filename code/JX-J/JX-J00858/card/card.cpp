#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,a[N],m,last[N],dp[N],vis[N],l[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=n;j>=1;j--){
        last[j]=l[a[j]];
        l[a[j]]=j;
        vis[a[j]]++;
        if(last[j]){
            for(int l=last[j];l>j;l--){
                vis[a[l]]--;
            }
        }
        for(int i=1;i<=m;i++){
            if(vis[i]){
                dp[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<dp[i]<<' ';
    }
    return 0;
}
