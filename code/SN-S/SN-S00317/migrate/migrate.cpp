#include<bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int Maxn=2e6+5,MaxN=5005;
int id,T,n,d,c[Maxn],f[MaxN][MaxN],Next[Maxn],x,ans,l,r,Mid,F[MaxN][MaxN];
int dfs(int x,int y){
	if(x==y)return 1;
	if(F[x][y]!=-1)return F[x][y];
	int ans=0;
	for(int i=x+1; i<=min(Next[x],y); i++){
		if(f[x][i]+f[i][y]!=f[x][y])continue;
		ans+=dfs(i,y);
		if(ans>2)return F[x][y]=ans;
	}
	return F[x][y]=ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>id>>T;
	while(T){
		T--;
		cin>>n>>d;
		for(int i=1; i<=n; i++){
			cin>>c[i];
		}
		if(n==1){
			cout<<0<<'\n';
			continue;
		}
		if(id>=11&&id<=12){
			d/=(c[2]-c[1]);
			if(d<2)cout<<0<<'\n';
			else cout<<max(0ll,n-2*d+1)<<'\n';
			continue;
		}
		for(int i=1; i<=n; i++){
			l=i+1;
			r=n;
			while(l<=r){
				Mid=(l+r)/2;
				if(c[Mid]-c[i]<=d)l=Mid+1;
				else r=Mid-1;
			}
			l--;
			Next[i]=l;
//			cout<<l<<' ';
		}
//		cout<<'\n';
		for(int i=1; i<=n; i++){
//			for(int j=1; j<=i; j++)cout<<"  ";
			for(int j=i+1; j<=n; j++){
				x=i;
				f[i][j]=1;
				while(Next[x]<j){
//					if(i==1&&j==5)cout<<x<<'\n';
					f[i][j]++;
					x=Next[x];
					if(x==Next[x]){
						f[i][j]=2*n;
						break;
					}
				}
//				cout<<f[i][j]<<' ';
			}
//			cout<<'\n';
		}
		ans=0;
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				F[i][j]=-1;
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				if(dfs(i,j)==2){
					ans++;
//					cout<<i<<' '<<j<<'\n';
				}
			}
//			cout<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
longlong

部分分拼包 
*/
