#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define range(i,x,y) for(int i=x;i<y;++i)
using namespace std;

vector<int> sum,a;

int get(int l,int r){
  return a[r]*(r-l+1)-sum[r]+sum[l-1];
}

signed main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0),cout.tie(0);
  int n,m;
  cin>>n>>m;
  a.resize(n+1);
  range(i,1,n+1){
    cin>>a[i];
  }
  sort(a.begin()+1,a.end());
  sum.resize(n+1);
  range(i,1,n+1){
    sum[i]=a[i]+sum[i-1];
  }
  int r=1;
  int mx=0;
  range(l,1,n+1){
    while(r<n&&get(l,r+1)<=m){
      ++r;
    }
    mx=max(mx,r-l+1);
    if(r==n){
      break;
    }
  }
  cout<<mx;
}