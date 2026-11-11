#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<int,ll>
#define fir first
#define se second
const int N=520,M=5e5+100;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll read(){
	ll x=0,f=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-')f=-1;
		s=getchar();
	}
	while(isdigit(s)){
		x=(x<<3)+(x<<1)+(s^48);
		s=getchar();
	}
	return x*f;
}
ll m[M];
vector<pll>v[M];
ll dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//memset(head,-1,sizeof head);
	int id,a,b,d,q;
	id=read(),a=read(),b=read(),d=read(),q=read();
	for(int i=1;i<=b;i++){
		m[i]=read();
		v[i].reserve(d);
	}
	for(int i=1;i<=a;i++){
		int len=read();
		int x,t;
		for(int j=1;j<=len;j++){
			x=read(),t=read();
			v[x].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=b;i++){
		for(int j=0;j<v[i].size();j++){
			int a1=v[i][j].fir;ll t1=v[i][j].se;
			for(int k=j+1;k<v[i].size();k++){
				int a2=v[i][k].fir;ll t2=v[i][k].se;
				//cout<<a1<<" "<<a2<<" "<<t1<<" "<<t2<<"\n";
				dis[a1][a2]=min(dis[a1][a2],t1+t2);
				dis[a2][a1]=min(dis[a2][a1],t1+t2);
			}
		}
	}
	for(int i=1;i<=a;i++){
		dis[i][i]=0;
	}
	for(int k=1;k<=a;k++){
		for(int i=1;i<=a;i++){
			for(int j=1;j<=a;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=a;i++){
//		for(int j=1;j<=a;j++){
//			cout<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
//		}
//	}
	while(q--){
		int qi,zh;
		qi=read(),zh=read();
		ll ans=inf;
		for(int i=0;i<v[qi].size();i++){
			for(int j=0;j<v[zh].size();j++){
				ans=min(ans,m[qi]+m[zh]+v[qi][i].se+v[zh][j].se+dis[v[qi][i].fir][v[zh][j].fir]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}