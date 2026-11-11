#include<bits/stdc++.h>
using namespace std;
vector<int> ds[300001];
int qs[300001];
int xd[300001];
int n,m;
int a[300001];
int ans[300001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
      for(int i=1;i<=m;i++)
        xd[i]=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        xd[a[i]]++;
        ds[a[i]].push_back(i);
    }

    for(int i=1;i<=n;i++){
        int now=i;
        qs[a[i]]++;
        qs[a[i]]=min(qs[a[i]],xd[a[i]]);
        int l=i;
        while(l!=n+1){
            ans[a[l]]++;
            l=ds[a[l]][xd[a[l]]]+1;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
