#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
long long r[2000005];
long long l[2000005];
long long pre[2000005];
long long dre[2000005];
void solve(){
	long long n,d;
	cin>>n>>d;
	for(long long i=1;i<=n;i++)cin>>x[i];
	r[0]=0;
	for(long long i=1;i<=n;i++){
		r[i]=max(i,r[i-1]);
		while(r[i]+1<=n && x[r[i]+1]-x[i]<=d)r[i]++;
	}
	l[n+1]=n+1;
	for(long long i=n;i>=1;i--){
		l[i]=min(i,l[i+1]);
		while(l[i]-1>=1 && x[i]-x[l[i]-1]<=d)l[i]--;
	}
//	for(long long i=1;i<=n;i++)cout<<l[i]<<' '<<r[i]<<'\n';
	for(long long nowl=1;nowl<=n;nowl++){
		pre[nowl]=0;
		if(l[nowl]==nowl || !(min(nowl-1,l[nowl+1]-1)-l[nowl]+1))continue;
		pre[nowl]=pre[l[nowl]]+min(nowl-1,l[nowl+1]-1)-l[nowl]+1;
	}
	for(long long nowr=n;nowr>=1;nowr--){
		dre[nowr]=0;
		if(r[nowr]==nowr || !(r[nowr]-max(nowr+1,r[nowr-1]+1)+1))continue;
		dre[nowr]=dre[r[nowr]]+r[nowr]-max(nowr+1,r[nowr-1]+1)+1;
	}
	long long ans=0;
	for(long long i=2;i+2<=n;i++)if(x[i+1]-x[i]<=d){
		//i,i+1 as ker
		//right:i can reach but i-1 can't
		//left:i+1 can reach but i+2 can't
		long long ll=l[i+1];
		long long lr=min(i-1,l[i+2]-1);
		long long rl=max(i+2,r[i-1]+1);
		long long rr=r[i];
		long long cnt=(rr-rl+1)*(lr-ll+1);
		if(cnt){
			ans+=cnt-1;
			long long nowl=ll,cntl=1;
			long long nowr=rr,cntr=1;
			if(ll==l[i])cntl+=pre[nowl];
			if(rr==r[i+1])cntr+=dre[nowr];
			ans+=cntl*cntr;
			ans+=(cntl-1)*(rr-rl);
			ans+=(cntr-1)*(lr-ll);
//			cout<<i<<' '<<i+1<<'\n';
//			cout<<cntl<<' '<<cntr<<'\n';
//			cout<<ll<<' '<<lr<<' '<<rl<<' '<<rr<<'\n';
//			cout<<ans<<'\n';
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long c,t;
	cin>>c>>t;
	while(t--)solve();
}
