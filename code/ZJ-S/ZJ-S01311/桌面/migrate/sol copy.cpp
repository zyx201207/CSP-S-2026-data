#include<bits/stdc++.h>
using namespace std;
int n,f[10005],g[10005],ans,pre[2000005],suf[2000005];
int tl[2000005],tr[2000005];
long long a[10005],d;
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
		printf("i=%d pre=%d suf=%d tl=%d tr=%d\n",i,pre[i],suf[i],tl[i],tr[i]);
	}
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			if(a[j]-a[i]<=d) continue;
			int cnt=0;
			for(int k=i+1; k<j; k++) cnt+=(a[k]-a[i]<=d && a[j]-a[k]<=d);
			if(cnt==2) {
				ans+=pre[i]*suf[j];
				printf("i=%d j=%d %d*%d\n",i,j,pre[i],suf[j]);	
			}
		}
	}
	cout<<ans<<'\n';
}
int main() {
	int c,T;
	cin>>c>>T;
	while(T--) ATRI();
}