#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int ans;
        for(int j=1;j<=n;j++)
        {
            if(a[j]==i) ans=j;
        }
        cout<<ans<<" ";
    }
    return 0;
}
