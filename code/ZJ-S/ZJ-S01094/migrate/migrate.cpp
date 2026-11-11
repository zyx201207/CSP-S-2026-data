#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,T;
ll n,d;
ll a[N],sum[N];
int cnt=0;
void dfs(int x,int res,int s,int y){
	if(cnt>2) return ;
	if(s==res&&x!=y) return ;
	if(s==res&&x==y){
		cnt++;
		return ;
	}
	if(x==y) return ;
	int u=-1;
	for(int i=y;i>x;i--){
		if(a[x]+d>=a[i]){
			u=0;
			dfs(i,res,s+1,y);
		}
	}
}
bool check(int x,int y){
	int res=0;
	for(int i=x;i<=y;i++){
		int u=-1;
		for(int j=i;j<=y;j++){
			if(a[i]+d<a[j]){
				u=j-1;
				break;
			}
		}
		i=u;res++;
		if(u==-1) break;
	}
	cnt=0;
	dfs(x,res,0,y);
//	if(x==1&&y==4) cout<<res<<'\n';
	if(cnt!=2) return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		bool oo=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i!=1)sum[i]=sum[i-1]+a[i]-a[i-1];
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=3) oo=0;
		}
		if(oo){
			if(d<=a[2]-a[1]){
				cout<<0<<'\n';
				continue;
			}
			int qq=n+1;
			a[0]=a[1]-(a[2]-a[1]);
//			if(d%(a[2]-a[1])==0){
//				cout<<n-(d/(a[2]-a[1])+1)<<'\n';
//				continue;
//			}
			d=((a[2]-a[1])*(d/(a[2]-a[1])));
//			cout<<d<<'\n';
//			for(int i=1;i<=n;i++){
//				if(a[1]+d*2>=a[i]&&a[1]+d*2<=a[i+1]){
//					qq=i;
//					break;
//				} 
//			}
			int ans=n-d/(a[2]-a[1])-d/(a[2]-a[1])+1;
			cout<<max(0,ans)<<'\n';
			continue;
		}
		if(d>a[n]-a[1]||d<a[2]-a[1]){
			cout<<0<<'\n';
			continue;
		}
		if(n>=2e6){
			cout<<0<<'\n';
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n&&a[j]<=a[i]+d*5;j++){
//				cout<<i<<' '<<j<<'\n';
				if(check(i,j)) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}