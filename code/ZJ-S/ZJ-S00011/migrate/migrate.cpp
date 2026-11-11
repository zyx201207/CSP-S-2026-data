#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
long long lim,a[maxn];
int n,degl[maxn],degr[maxn],posr[maxn],posl[maxn],vis[maxn];
int fl[maxn],fr[maxn];
long long pre[maxn],suf[maxn],cntl[maxn],cntr[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>lim;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=0;i<=n+1;i++){
			degl[i]=degr[i]=0;
			pre[i]=suf[i]=0;
			posl[i]=posr[i]=0,vis[i]=0;
			cntl[i]=0,cntr[i]=0;
		}
		int r=1;
		long long ans=0;
		for(int i=1;i<=n;i++){
			while(r<n and a[r+1]-a[i]<=lim) r++;
			fr[i]=r;
			degr[r]++;
			if(fr[i]-i>=2) cntl[fr[i]]++;
		}
		int l=n;
		for(int i=n;i>=1;i--){
			while(l>1 and a[i]-a[l-1]<=lim) l--;
			fl[i]=l;
			degl[l]++;
			if(i-fl[i]>=2) cntr[fl[i]]++;
		}
		for(int i=1;i<=n;i++){
			if(fr[i]!=i and fl[fr[i]]==i){
				posr[i]=fr[i];
				posl[fr[i]]=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			long long sum=0;
			int u=i;
			while(u){
				sum+=degr[u];
				pre[u]=sum;
				vis[u]=1;
				u=posr[u];
			}
		}
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=n;i>=1;i--){
			if(vis[i]) continue;
			long long sum=0;
			int u=i;
			while(u){
				sum+=degl[u];
				suf[u]=sum;
				vis[u]=1;
				u=posl[u];
			}
		}
		for(int i=1;i<=n;i++){
			if(i<n) ans+=1ll*cntl[i+1]*cntr[i];
			if(fr[i]!=i and fr[fr[i]]!=fr[i]){
				if(fr[i]-fl[fr[fr[i]]]==1 and i==fl[fl[fr[fr[i]]]]){
					ans+=1ll*pre[i]*suf[fr[fr[i]]];
				}
				if(fr[i]-fl[fr[fr[i]]]==1){
					ans+=suf[fr[fr[i]]];
				}
			}
			if(fl[i]!=i and fl[fl[i]]!=fl[i]){
				if(fr[fl[fl[i]]]-fl[i]==1){
					ans+=pre[fl[fl[i]]];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}