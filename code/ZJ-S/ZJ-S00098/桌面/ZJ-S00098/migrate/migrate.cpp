#include<bits/stdc++.h>
using namespace std;
using i64=long long;
constexpr int N=1e3+10;

int subtask;
int n;
i64 ans,d,x[N],dis[N][N],cnt[N][N],s[N][N];

struct SegmentTree{

}T;

void solve(){
  cin>>n>>d,ans=0;
  for(int i=0;i<=n;++i)for(int j=0;j<=n;++j)s[i][j]=0;
  for(int i=1;i<=n;++i)cin>>x[i];
  for(int i=n;i;--i){
    int lst=-1;
    for(int j=i+1;j<=n;++j){
      if(x[j]-x[i]<=d){
        dis[j][i]=1;
        cnt[j][i]=1;
        for(int k=i;k<=n;++k)s[j][k]+=1;
        lst=j;
        continue;
      }
      i64 mnd=dis[j][lst];
      dis[j][i]=mnd+1;
      int l=i,r=lst;
      while(l+1!=r){
        int mid=(l+r)>>1;
        if(dis[j][mid]<mnd)l=mid;
        else r=mid;
      }

      // if(i==1&&j==4){
      //   cout<<"test\n";
      //   cout<<mnd<<"\n";
      //   cout<<"l="<<l<<",r="<<r<<",lst="<<lst<<"\n";
      //   cout<<s[j][lst]<<" "<<s[j][r-1]<<"\n";
      // }

      // [r,lst]
      cnt[j][i]=s[j][lst]-s[j][r-1];
      if(cnt[j][i]==2)++ans;
      for(int k=i;k<=n;++k)s[j][k]+=cnt[j][i];
    }
  }

  // for(int i=1;i<=n;++i){
  //   for(int j=i+1;j<=n;++j){
  //     cout<<i<<"->"<<j<<" "<<cnt[j][i]<<"\n";
  //   }
  // }

  cout<<ans<<"\n";
}

int main(){
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  int T;for(cin>>subtask>>T;T;--T)solve();
  return 0;
}