#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define il inline

const int N=5e5+5,M=3e5+5,mod=1e9+7;

int n,m,f=1,sum=1;
int a[N];
bool vis[M];
int Lst[M],ans[M];

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];if(i>=2) if(a[i]<a[i-1]) f=0;}
	if(f){
		for(int i=2;i<=n;i++){if(a[i]!=a[i-1]) cout<<sum<<' ';sum++;}
		cout<<sum;return 0;
	}
	for(int i=1;i<=n;i++) if(!vis[a[i]]){vis[a[i]]=1;for(int j=n;j>=i;j--) if(a[j]==a[i]){Lst[a[i]]=j;break;}}
	for(int i=1;i<=n;i++) for(int j=Lst[a[i]];j<=n;j=Lst[a[j+1]]){ans[a[j]]++;if(j==n) break;}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
