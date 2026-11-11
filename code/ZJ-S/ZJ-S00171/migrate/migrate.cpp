#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll getint(){
	char ch=getchar();
	ll res=0; int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0'; ch=getchar();
	}
	return res*f;
}
void putint(ll x){
	if(x<10){
		putchar(x+'0'); return ;
	}
	putint(x/10); putchar(x%10+'0');
}
ll a[2000005];
int cnt[2000005],dp[2000005];
int q[2000005],C[2000005];
int nxt[2000005];
int E[25];
vector<int> V[2000005];
int L[2000005],f[2000005];
int pre[2000005],g[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T; c=getint(),T=getint();
	while(T--){
		memset(dp,0,sizeof(dp));
		int n; ll d; n=getint(); d=getint();
		for(int i=1;i<=n;i++) a[i]=getint();
		if(n==1){
			puts("0"); continue;
		}
		if(1<=c&&c<=10){
			ll ans=0;
			for(int i=1;i<n;i++){
				if(a[i+1]-a[i]>d) continue;
				for(int j=0;j<=n;j++) dp[j]=cnt[j]=C[j]=0;
				int l=i,r=i,head=1,tail=1; q[head]=i; cnt[0]=C[i]=1;
 				for(int j=i+1;j<=n;j++){
					while(l<j&&a[j]-a[l]>d) l++;
					while(head<=tail&&q[head]<l){
						cnt[dp[q[head]]]-=C[q[head]]; head++;
					}
					int R=r;
					while(r<j-1&&a[j]-a[r+1]<=d) r++;
					for(int k=R+1;k<=r;k++){
						while(head<=tail&&dp[k]<dp[q[tail]]){
							cnt[dp[tail]]--; tail--;
						}
						q[++tail]=k; cnt[dp[k]]+=C[k];
					}
					dp[j]=dp[q[head]]+1; C[j]=cnt[dp[q[head]]];
					if(cnt[dp[q[head]]]==2) ans++;
				}
			}
			putint(ans); putchar('\n');
		}
		else if(c==11||c==12){
			ll x=d/(a[2]-a[1]);
			if(x<=1) puts("0");
			else{
				putint(max(0ll,n-2*x+1)); putchar('\n');
			}
		}
		else if(13<=c&&c<=18){
			ll ans=0;
			for(int i=1;i<=n;i++) V[i].clear();
			for(int i=1;i<=n;i++){
				nxt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
			}
			nxt[n+1]=n+1;
			for(int j=1;j<=n;j++) L[j]=lower_bound(a+1,a+n+1,a[j]-d)-a;
			for(int j=1;j<=n;j++) pre[j]=0,g[j]=0;
			for(int j=1;j<=n;j++) g[L[j]]++;
			for(int j=1;j<=n;j++) pre[j]=pre[j-1]+g[j];
			for(int i=1;i<=n;i++){
				int x=i;
				for(int j=0;j<=20;j++){
					E[j]=x; x=nxt[x];
				}
				for(int j=1;j<=20;j++) f[E[j]]=f[E[j]-1]=0;
				f[i]=1;
				for(int tmp=0;tmp<=20;tmp++){
					V[E[tmp]].clear();
					if(E[tmp]-1>=0) V[E[tmp]-1].clear();
				}
				for(int tmp=0;tmp<=20;tmp++){
					if(tmp&&E[tmp]==E[tmp-1]) continue;
					int j=E[tmp];
					V[max(i,L[j])].push_back(j);
					if(!tmp||E[tmp-1]<E[tmp]-1){
						j=E[tmp]-1;
						V[max(i,L[j])].push_back(j);
					}
				}
				for(int j=0;j<=20;j++){
					if(j&&E[j]-E[j-1]>=2&&f[E[j]-1]==1&&f[E[j]]==1){
						if(E[j]-1==i) ans+=pre[E[j]-1];
						else ans+=g[E[j]-1];
						for(int k:V[E[j]-1]) f[k]=2;
					}
					else if(f[E[j]]==2){
						if(E[j]==i) ans+=pre[E[j]];
						else ans+=g[E[j]];
						for(int k:V[E[j]]) f[k]=2;
					}
					if(f[E[j]]==1){
						for(int k:V[E[j]]) f[k]=1;
					}
				}
			}
			putint(ans); putchar('\n');
		}
		else puts("0");
	}
	return 0;
}
