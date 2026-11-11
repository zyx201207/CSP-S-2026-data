#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll meiyong,n,m,D,q;
ll w[500010];
ll num[510],d[510][510];
vector<ll> t[510],a[510],From[500010],tt[500010];
ll read(){
	char c=getchar();
	ll flag=1,res=0;
	while(c>'9'||c<'0'){
		if(c=='-') flag=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*flag;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(d,0x3f,sizeof(d));
	meiyong=read(),n=read(),m=read(),D=read(),q=read();	
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		num[i]=read();
		for(int j=1;j<=num[i];j++){
			ll x=read(),y=read();
			a[i].push_back(x);
			t[i].push_back(y);
			tt[x].push_back(y);
			From[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<num[i];j++){
			for(int k=0;k<From[a[i][j]].size();k++){
				int nxt=From[a[i][j]][k];
				if(nxt<=i) continue;
				d[i][nxt]=d[nxt][i]=min(d[i][nxt],t[i][j]+tt[a[i][j]][k]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<(d[i][j]==0x3f3f3f3f3f3f3f3f?-1:d[i][j])<<" ";
//		}
//		cout<<endl;
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(d[i][k]==0x3f3f3f3f3f3f3f3f) continue;
			for(int j=1;j<=n;j++){
				if(i!=j) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	while(q--){
		int x=read(),y=read();
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<From[x].size();i++){
			for(int j=0;j<From[y].size();j++){
				ans=min(ans,d[From[x][i]][From[y][j]]+w[x]+w[y]+tt[x][i]+tt[y][j]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
