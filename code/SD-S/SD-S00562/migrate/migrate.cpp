#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000005,inf=0x3f3f3f3f;
int n,l[N],r[N],dpl[N],dpr[N],dp[N],dis[N],cnt[N],dl[N],dr[N],rp[N];
ll d,a[N],sum[N];
queue<ll>q;
int pos[N],posm[N];
void solve1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[i]=0;r[i]=0;
		dis[i]=inf;dp[i]=0;
	}
	for(int i=1;i<=n;i++){
		while(!q.empty()&&a[i]-a[q.front()]>d)q.pop();
		q.push(i);
		if(!q.empty())l[i]=q.front();
	}
	while(!q.empty())q.pop();
	for(int i=n;i>=1;i--){
		while(!q.empty()&&-a[i]+a[q.front()]>d)q.pop();
		q.push(i);
		if(!q.empty())r[i]=q.front();
	}
	while(!q.empty())q.pop();
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[j]=inf;
			dp[j]=0;
		}
		dis[i]=0;dp[i]=1;
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=r[j];k++){
				if(dis[k]>dis[j]+1){
					dis[k]=dis[j]+1;dp[k]=dp[j];
				}
				else{
					if(dis[k]==dis[j]+1)dp[k]+=dp[j];
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(dp[j]==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
void solve2(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[i]=0;r[i]=0;
		dis[i]=inf;dp[i]=0;
		cnt[i]=0;
	}
	for(int i=1;i<=n;i++){
		while(!q.empty()&&a[i]-a[q.front()]>d)q.pop();
		q.push(i);
		if(!q.empty())l[i]=q.front();
	}
	while(!q.empty())q.pop();
	for(int i=n;i>=1;i--){
		while(!q.empty()&&-a[i]+a[q.front()]>d)q.pop();
		q.push(i);
		if(!q.empty())r[i]=q.front();
	}
	while(!q.empty())q.pop();
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(l[i]<=i-2)ans+=cnt[l[i]+1];
		cnt[r[i]]++;
	}
	cout<<ans<<'\n';
}
void solve3(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[i]=0;r[i]=0;
		pos[i]=inf;posm[i]=0;
		dpl[i]=0;dpr[i]=0;
		dl[i]=0;rp[i]=0;dr[i]=0;
	}
	for(int i=1;i<=n;i++){
		while(!q.empty()&&a[i]-a[q.front()]>d)q.pop();
		q.push(i);
		if(!q.empty())l[i]=q.front();
	}
	while(!q.empty())q.pop();
	for(int i=n;i>=1;i--){
		while(!q.empty()&&-a[i]+a[q.front()]>d)q.pop();
		q.push(i);
		if(!q.empty())r[i]=q.front();
	}
	while(!q.empty())q.pop();
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(l[i]<=i-2){
			dl[i]=(pos[l[i]+1]==0x3f3f3f3f ? 0 : pos[l[i]+1]);
			rp[i]=posm[l[i]+1];
		}
		pos[r[i]]=min(pos[r[i]],i);
		posm[r[i]]=max(posm[r[i]],i);
	}
	for(int i=1;i<=n;i++){
		pos[i]=0;
	}
	for(int i=n;i>=1;i--){
		if(r[i]>=i+2)dr[i]=(pos[r[i]-1]!=0 ? pos[r[i]-1] : n+1);
		else dr[i]=n+1;
		pos[l[i]]=max(pos[l[i]],i);
	}
	int pl=0;
	for(int i=1;i<=n;i++){
		pl=max(pl,dl[i]);
		if(a[i]-a[i-1]>d){
			pl=i-1;
		}
		if(r[i-1]<=i)dpl[i]=(i-pl);
		else dpl[i]=1;
		sum[i]=sum[i-1]+dpl[i];
	}
	int pr=n+1;
	for(int i=n;i>=1;i--){
		pr=min(pr,dr[i]);
		if(a[i+1]-a[i]>d){
			pr=i+1;
		}
		if(l[i+1]>=i)dpr[i]=(pr-i);
		else dpr[i]=1;
	}
	for(int i=1;i<=n;i++){ 
		ans+=(sum[rp[i]]-(dl[i]==0 ? 0 : sum[dl[i]-1]))*dpr[i];
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int cas,T;
	cin>>cas>>T;
	if(0<=cas&&cas<=6)while(T--)solve1();
	else if(11<=cas&&cas<=14)while(T--)solve2();
	else while(T--)solve3();
	return 0;
}
//春江潮水连海平，海上明月共潮生 
