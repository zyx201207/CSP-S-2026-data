#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],b[40],vis[200005],ans;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    b[0]=1;
    for(int i=1;i<=30;i++)
      b[i]=b[i-1]*2;
    for(int i=1;i<=n;i++)
      vis[i]=1;
    for(int i=30;i>=0;i--){
        vector<int> v;
        for(int j=1;j<=n;j++)
          if(a[j]&(1<<i))
            v.push_back(j);
        if(v.size()<m)
          continue;
        int sum=0;
        for(int j:v)
          if(vis[j])
            sum++;
        if(sum>=m){
            ans+=b[i];
            for(int j=1;j<=n;j++)
              if(vis[j]&&(!(a[j]&(1<<i))))
                vis[j]=0;
        }
    }
    cout<<ans;
    return 0;
}
