#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000010],f[1000010],ans,ff[1000010];
vector<int >v[40];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<=30;i++){
		for(int j=1;j<=n;j++)
			if((1<<i)&a[j]) v[i].push_back(j);
	}
	for(int i=0;i<=n;i++) f[i]=1;
	for(int i=30;i>=0;i--){
		int xx=0;
		for(int x:v[i]) if(f[x]) xx++;
		if(xx<m) continue;
		ans+=(1<<i);
		for(int i=1;i<=n;i++) ff[i]=0;
		for(int x:v[i]) ff[x]=1;
		for(int i=1;i<=n;i++)if(!ff[i]) f[i]=0;
	}
	cout<<ans<<"\n";
	return 0;
}