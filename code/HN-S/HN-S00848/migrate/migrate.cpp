#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e6 + 5;
int x[N],n,d,c,t,nxt[N],yg[N],yt[N],pre[N],to1[N],to2[N],onl[N];
vector<int> vp[N],sp[N];
int cx(vector<int> &v,vector<int> &s,int l,int r){
  return s[upper_bound(v.begin(),v.end(),r) - v.begin()]  - s[lower_bound(v.begin(),v.end(),l) - v.begin()];
}
int cx(vector<int> &v,int l,int r){
  if (l > r){
    return 0;
  }
  return upper_bound(v.begin(),v.end(),r) - lower_bound(v.begin(),v.end(),l);
}
void solve(){
  cin >> n >> d;
  for (int i = 1;i <= n;i++){
    cin >> x[i];
    vp[i].clear();
  }
  pre[1] = 1;
  for (int i = 2;i <= n;i++){
    pre[i] = pre[i - 1];
    for (;x[i] - x[pre[i]] > d;pre[i]++){}
    
  }
  nxt[n] = n;
  for (int i = n - 1;i >= 1;i--){
    nxt[i] = nxt[i + 1];
    for (;x[nxt[i]] - x[i] > d;nxt[i]--){}
  }
  fill(yg + 1,yg + n + 1,0);
  fill(to1 + 1,to1 + n + 1,0);
  fill(to2 + 1,to2 + n + 1,0);
  //cerr << "\n";
  for (int i = 1;i <= n;i++){
    vp[pre[i]].push_back(i);
  }
  int ans = 0;
  for (int i = n;i >= 1;i--){
    if (nxt[i] == i){
      to1[i] = to2[i] = yg[i] = 0;
      continue;
    }
    int t1 = nxt[i],t2 = nxt[t1],t3 = nxt[t2];
    to1[i] = to1[t1],to2[i] = to2[t1];
    to1[i] += max(0ll,cx(vp[t1 - 1],t1 + 1,t2));
    yg[i] = yg[t1] + cx(vp[i],i + 1,t1);
    if (pre[t1] < i){
      yg[i] = 0;
    }
    
    if (pre[t2] < t1){
      to1[i] -= to1[t1],to2[i] -= to2[t1];
      if (pre[t2] == t1 - 1){
        to2[i] += yg[t2];
      }
    }
    else if (pre[t2 - 1] < t1){
      to1[i] -= cx(vp[t2 - 1],t2 + 1,t3);
      if (pre[t3] == t2 - 1){
        to2[i] -= yg[t3];
      }
    }
    ans += to1[i] + to2[i];

  }
  cout << ans << "\n";
}
signed main(){
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  for (cin >> c >> t;t--;){
    solve();
  }
  cerr << clock() << "\n";
}