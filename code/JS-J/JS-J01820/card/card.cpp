#include<bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;
int n,m;
int a[N],ans[N],lst[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--) if(!lst[a[i]]) lst[a[i]]=i;
    for(int i=1;i<=n;i++){
        int j=i;
        while(j<=n){
            j=lst[a[j]];
            ans[a[j]]++;
            j++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}