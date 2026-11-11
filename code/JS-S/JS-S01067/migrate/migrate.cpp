#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int T, n, d, a[N], L[N], R[N], fr[N], fl[N], cr[N], cl[N];
void clear(){
	for(int i=0; i<=n+2; i++)fl[i]=fr[i]=L[i]=R[i]=cl[i]=cr[i]=0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>T>>T;
	while(T--){
		clear();
		cin>>n>>d;
		for(int i=1; i<=n; i++)cin>>a[i];
		for(int i=1; i<=n; i++){
			R[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
			L[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
			if(L[i]<i-1)cl[L[i]]++;
			if(R[i]>i+1)cr[R[i]]++;
		}
		for(int i=1; i<=n; i++){
			if(R[i]!=i)fr[R[i]]+=1;
			if(R[i]!=i&&R[i-1]!=R[i]){
				fr[R[i]]+=fr[i];
			}
		}
		for(int i=n; i; i--){
			if(L[i]!=i)fl[L[i]]+=1;
			if(L[i]!=i&&L[i+1]!=L[i]){
				fl[L[i]]+=fl[i];
			}
		}
		int ans=0;
		for(int i=1; i<n; i++)if(R[i]>i+1&&L[i+1]<i&&L[i+1]==L[i]&&R[i+1]==R[i]){
			ans=(ans+fl[i]*fr[i+1]);
		}
		for(int i=1; i<n; i++)if(L[i+1]==L[i]&&R[i]>i+1&&L[i+1]<i&&R[i+1]!=R[i])ans+=cl[i]*fr[i+1];
		for(int i=1; i<n; i++)if(R[i+1]==R[i]&&R[i]>i+1&&L[i+1]<i&&L[i+1]!=L[i])ans+=cr[i+1]*fl[i];
		for(int i=1; i<n; i++)if(R[i]>i+1&&L[i+1]<i&&L[i+1]!=L[i]&&R[i+1]!=R[i])ans+=cl[i]*cr[i+1];
		cout<<ans<<'\n';
	}
	return 0;
}