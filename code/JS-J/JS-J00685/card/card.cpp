#include<bits/stdc++.h>
using namespace std;
#define int long long
int mp[500005],ans[500005];
int n,m,a[500005];
signed main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int sum=1;
        for(int j=1;j<=m;j++) mp[j]=0;
        for(int j=1;i<=n;j++){
            if(mp[a[j]]!=0&&j<sum){
                sum=j;
            }
            mp[a[j]]=j;
        }
        for(int j=1;j<=m;j++) if(mp[i]>=sum)ans[j]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
//hyw

}
