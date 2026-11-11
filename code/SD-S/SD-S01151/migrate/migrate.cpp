#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int n,nxt[N],pre[N]; 
ll d,a[N],ans,lenpre[N],lennxt[N];
void solve(){
	scanf("%d%lld",&n,&d); ans=0;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=0;i<=n+1;i++)	pre[i]=n+1,nxt[i]=lenpre[i]=lennxt[i]=0;
	for(int i=1,j=1;i<=n;i++){
		while(j<=n&&a[j]-a[i]<=d) j++;
		nxt[i]=j-1;
	}
	for(int i=n,j=n;i>=1;i--){
		while(j>=1&&a[i]-a[j]<=d) j--;
		pre[i]=j+1;
	}
	for(int i=n;i>=1;i--){
		int v1=nxt[i],v2=nxt[i-1]+1;
		lennxt[i]=max(0,v1-v2+1);
		if(v1==v2) lennxt[i]+=lennxt[v1];
	}
	for(int i=1;i<=n;i++){
		int v1=pre[i],v2=pre[i+1]-1;
		lenpre[i]=max(0,v2-v1+1);
		if(v1==v2) lenpre[i]+=lenpre[v1];
	}
	for(int i=2;i<=n;i++){
		int v1=pre[i],v2=v1+1;
		int v11=pre[v1],v22=pre[v2+1]-1;
		if(v22<v11||v22==0||v22-max(v11,pre[v2])<0) continue;
		ans+=1ll*((i>v2&&i<=nxt[v2])+(nxt[v2]==i)*lennxt[i])*(v22-max(v11,pre[v2])+1+(v22==v11)*lenpre[v11]);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t; scanf("%d%d",&c,&t);
	while(t--) solve();
	return 0;
}
