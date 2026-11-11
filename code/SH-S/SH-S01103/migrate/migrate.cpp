#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+9;
int cid,T,n,d,a[N],val[N],as[N],val2[N],as2[N],pre[N],nxt[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i],val[i]=as[i]=val2[i]=as2[i]=nxt[i]=pre[i]=0;
	nxt[0]=1;
	for(int i=1;i<=n;i++){
		nxt[i]=nxt[i-1];
		while(nxt[i]<n&&a[nxt[i]+1]-a[i]<=d) nxt[i]++;
	}
	pre[n+1]=n;
	for(int i=n;i>=1;i--){
		pre[i]=pre[i+1];
		while(pre[i]>1&&a[i]-a[pre[i]-1]<=d) pre[i]--;
	}
	int now=1;
	for(int i=1;i<=n;i++){
		while(now<n&&a[now+1]-a[i]<=d) now++;
		int j=i;
		while(j<n&&(now==n||a[now+1]-a[j+1]>d)) j++;
		val[now]=val[i]+j-i+1;
		if(now>1&&pre[now-1]>=i&&pre[now-1]<now-1) as[now]+=val[pre[now-1]];
		for(int k=i;k<=min(j,now-2);k++) as[now]++;
		i=j;
	}
	now=n;
	for(int i=n;i>=1;i--){
		while(now>1&&a[i]-a[now-1]<=d) now--;
		int j=i;
		while(j>1&&(now==1||a[j-1]-a[now-1]>d)) j--;
		val2[now]=val2[i]+i-j+1;
		if(now<n&&nxt[now+1]<=i&&nxt[now+1]>now+1) as2[now]+=val2[nxt[now+1]];
		for(int k=max(j,now+2);k<=i;k++) as2[now]++;
		i=j;
	}
	int ans=0;
	for(int i=2;i<n-1;i++)
		if(a[i+1]-a[i]<=d) ans+=as[i+1]*as2[i];//cout<<as[i+1]<<' '<<as2[i]<<'\n'; 
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>cid>>T;
	while(T--) solve();
	return 0;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/
