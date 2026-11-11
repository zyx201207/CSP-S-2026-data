#include<bits/stdc++.h>
using namespace std;
int a[200005];
int k;
bool cmp(int x,int y){
	return ((x>>k)&1)>((y>>k)&1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=29;i>=0;i--){
		k=i;
		sort(a+1,a+n+1,cmp);
		//for(int i=1;i<=n;i++)cerr<<a[i]<<' ';
		//cerr<<'\n';
		int j=1;
		for(;j<=n;j++){
			if(!((a[j]>>i)&1))break;
		}
		if(j>m)n=j-1,ans|=(1<<i);
		//cerr<<j<<'\n';
	}
	cout<<ans;
	return 0;
}
/*
__/\__
\    /
/_  _\
  \/
*/
