#include<bits/stdc++.h>
#define ll long long
#define N 2000005
#define to(u) nxt[nxt[u]-1]
using namespace std;
int c,T,n,nxt[N],last[N];
ll d,x[N],dis[5005][5005],ans;
vector<int> ve;
ll rd(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	return x*f;
}
void work(){
	ans=0;
	ve.clear();
	n=rd(),d=rd();
	for(int i=1;i<=n;i++) x[i]=rd();
	for(int i=1;i<=n;i++) nxt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1,last[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
	for(int i=1;i<=n;i++){
		if(i<nxt[i]-1&&nxt[i]<nxt[nxt[i]-1]&&nxt[nxt[i]-2]<nxt[nxt[i]-1]) ve.push_back(i);
	}
	for(int i=0;i<ve.size();i++){
		int u=ve[i],v=to(u);
		ll L,R;
		if(i==0){
			int j=u;
			while(nxt[j]!=j&&j>=1) j--;
			L=u-j;
		}
		else L=(u-ve[i-1]);
		if(i==ve.size()-1){
			int j=v;
			while(last[j]!=j&&j<=n) j++;
			R=j-v;
		}
		else R=to(ve[i+1])-v;
		ans+=L*R;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd(),T=rd();
	while(T--) work();
	return 0;
}
