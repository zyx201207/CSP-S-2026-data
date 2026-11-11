#include<bits/stdc++.h>
using namespace std;
#define F(i,s,e) for(int i=s;i<=e;i++)

const int N = 2e5+10;
int a[N],vis[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;cin>>n>>m;int ans=0;
	F(i,1,n) cin>>a[i];
	for(int k=30;k>=0;k--){
		int cnt=0;
		F(i,1,n) if(!vis[i]&&((a[i]>>k)&1)) cnt++;
		if(cnt>=m){
			ans|=(1<<k);
			F(i,1,n) if(!vis[i]&&!((a[i]>>k)&1)) vis[i]=1;
		}
	}
	cout<<ans;
	return 0;
}


