#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200001;
int n,m,a[N],ans;
void dfs(int i,int j,int s){
    if(i>=m){
		ans=max(ans,s);
		return;
	}
	if(j+m-i-1>n){
		cout<<j<<":"<<i<<":"<<s<<'\n';
		return;
	}
	for(int nj=j;nj<=n;nj++){
		dfs(i+1,nj+1,s & a[nj]);
	}
	
}
signed main(){
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++){
  	cin>>a[i];
  }
  for(int i=1;i<=n;i++){
  	dfs(1,i+1,a[i]);
  }
  cout<<ans;
  return 0;
}
