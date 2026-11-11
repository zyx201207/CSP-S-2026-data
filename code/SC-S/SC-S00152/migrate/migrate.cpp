#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005;
ll c,n,d,a[N],dp[N][N][2],st[N]={0};
priority_queue<array<ll,2>>q,whi;
ll read(){
	ll num=0,f=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-')f=-1;
		s=getchar();
	}
	while(isdigit(s)){
		num=num*10+(s^48);
		s=getchar();
	}return num*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();int t=read();
	while(t--){
		n=read();d=read();
		bool fg=1;
		ll ch=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(i>2&&ch!=a[i]-a[i-1]){
				fg=0;
			} 
			ch=a[i]-a[i-1];
		}
		if(fg){
			if(ch<d)cout<<max(n-2*(d/ch)+1,0ll)<<'\n';
			else cout<<0<<'\n';
			continue;
		}else if(n>N){
			cout<<0<<'\n';
			continue;
		}
		memset(dp,63,sizeof(dp));
		ll ans=0;
		for(int l=1;l<=n;l++){
			q=whi;
			while(!q.empty())q.pop();
			memset(st,0,sizeof(st));
			dp[l][l][0]=0;dp[l][l][1]=1;
			st[0]=1;
			q.push(array<ll,2>{dp[l][l][0],l});
			int ls=l;
			for(int r=l+1;r<=n;r++){
				while(!q.empty()&&a[r]-a[q.top()[1]]>d){
					auto nw=q.top();
					q.pop();
				}
				while(ls+1<r&&a[r]-a[ls]>d){
					if(dp[l][ls][0]>N){
						ls++;continue;
					}
					st[dp[l][ls][0]]-=dp[l][ls][1];
					ls++;
				}
				if(!q.empty()){
					auto nw=q.top();
					dp[l][r][0]=-nw[0]+1;
					dp[l][r][1]=st[-nw[0]];
					st[-nw[0]+1]+=dp[l][r][1];
					q.push(array<ll,2>{-dp[l][r][0],r});
				}
				if(dp[l][r][1]==2){
					ans++;
				}
			}
		}cout<<ans<<'\n';
	}
	return 0;
}