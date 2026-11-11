#include<bits/stdc++.h>
using namespace std;
int n,pre[2000005],suf[2000005];
int tl[2000005],tr[2000005],cl[2000005],cr[2000005];
long long a[2000005],d,ans;
void corelr(int x, int y) {
	long long res=1;
	if(tr[tr[x]]<=y) res*=suf[y];
	if(tl[tl[y]]>=x) res*=pre[x];
	ans+=res;
}
void corel(int x, int y) {
	long long res=1;
	if(tl[tl[y]]>=x) res*=pre[x];
	ans+=res;
}
void corer(int x, int y) {
	long long res=1;
	if(tr[tr[x]]<=y) res*=suf[y];
	ans+=res;
}
void ATRI() {
	cin>>n>>d;
	ans=0;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1,j=1; i<=n; i++) {
		while(a[i]-a[j]>d) j++;
		tl[i]=j;
	}
	for(int i=n,j=n; i>=1; i--) {
		while(a[j]-a[i]>d) j--;
		tr[i]=j;
	}
	pre[1]=1;
	for(int i=2; i<n; i++) {
		if(tl[i]==tl[i+1]) pre[i]=1;
		else pre[i]=pre[tl[i]]+tl[i+1]-tl[i];
	}
	suf[n]=1;
	for(int i=n-1; i>=2; i--) {
		if(tr[i]==tr[i-1]) suf[i]=1;
		else suf[i]=suf[tr[i]]+tr[i]-tr[i-1];
	}
	for(int i=1; i<=n; i++) {
		cl[i]=-1, cr[i]=-1;
		if(tr[i]>=i+2) {
			cl[i]=tr[tr[i]-2]+1, cr[i]=tr[tr[i]-1];
			if(cl[i]>cr[i]) cl[i]=cr[i]=-1;
		}
	}
	int mx=0;
	for(int i=1; i<=n; i++) {
		if(cl[i]!=-1) {
			// for(int j=cl[i]; j<=cr[i]; j++) {
			// 	printf("core %d %d\n",i,j);
			// }
			if(cr[i]>mx) {
				ans+=max(mx-cl[i]+1,0);
				for(int j=max(mx+1,cl[i]); j<cr[i]; j++) corel(i,j);
				corelr(i,cr[i]);
				mx=cr[i];
			} else if(cr[i]==mx) {
				ans+=mx-cl[i];
				corer(i,cr[i]);
			} else {
				ans+=cr[i]-cl[i]+1;
			}
			// cout<<ans<<'\n';
		}
	}
	// for(int i=1; i<=n; i++) {
	// 	printf("i=%d pre=%d suf=%d tl=%d tr=%d\n",i,pre[i],suf[i],tl[i],tr[i]);
	// }
	cout<<ans<<'\n';
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--) ATRI();
}