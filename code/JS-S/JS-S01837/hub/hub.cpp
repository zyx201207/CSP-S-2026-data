#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF ((int)(4e18))
#define PII pair<int,int>
#define range(i,x,y) for(int i=x;i<y;++i)
#define in(x,a) for(auto x:a)
using namespace std;

signed main(){
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0),cout.tie(0);
  int c,T;
  cin>>c>>T;
  while(T--){
    int n,k;
    cin>>n>>k;
    range(i,1,n){
      int t;
      cin>>t;
    }
    if(k==n){
      cout<<0<<endl;
    }else if(k>=(n>>1)){
      cout<<1<<endl;
    }else{
      cout<<((n>>1)-k)<<endl;
    }
  }
  return 0;
}