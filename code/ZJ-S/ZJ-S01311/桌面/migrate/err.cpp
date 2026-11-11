#include<bits/stdc++.h>
using namespace std;
int n,f[10005],g[10005],ans,pre[2000005],suf[2000005];
long long a[10005],d;
void ATRI() {
	cin>>n>>d;
	ans=0;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<n; i++) {
		if(i>1 && a[i]-a[i-1]<=d && a[i+1]-a[i-1]>d) pre[i]=pre[i-1]+1;
		else pre[i]=1;
	}
	for(int i=n; i>=2; i--) {
		if(i<n && a[i+1]-a[i]<=d && a[i+1]-a[i-1]>d) suf[i]=suf[i+1]+1;
		else suf[i]=1;
	}
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			if(a[j]-a[i]<=d) continue;
			int cnt=0;
			for(int k=i+1; k<j; k++) cnt+=(a[k]-a[i]<=d && a[j]-a[k]<=d);
			if(cnt==2) {
				ans+=pre[i]*suf[j];
				// printf("i=%d j=%d %d*%d\n",i,j,pre[i],suf[j]);	
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