#include<bits/stdc++.h>
#define int long long
#define INF (1ll<<62)
#define pii pair<int,int>
using namespace std;
int n,m,a[500010],f[500010];
bool vis[500010];
int sum=0;
bool id_deng=0;
int maxn=-INF,minn=INF;
int opn;
bool cmp(int x,int y){
	return abs(x-opn)<abs(y-opn);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]=1;
		if(i>2 and a[i]-a[i-1]!=a[i-1]-a[i-2])  id_deng=1;
	}
	
	if(!id_deng){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)  f[i]=f[i-1]+a[i];
		for(int i=n;i>=1;i--){
		
			if(a[i]*i-f[i]<=m){
				cout<<i;
				return 0;
			}
		}
		cout<<0; 
		return 0;
	}
	else{
		maxn=a[n],minn=a[1];
		int ans=-INF;
		for(int i=minn;i<=maxn;i++){
			if(!vis[i])  continue;
			opn=i;
			sort(a+1,a+n+1,cmp);
			int yiuo=0,oki=0;
			for(int j=1;j<=n;j++){
				yiuo+=abs(a[j]-i);
				if(yiuo>m)  break;
				oki++; 
			}
			ans=max(ans,oki);
		}
		cout<<ans;
	}
	return 0;
}
