#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+9,Inf=5e18+9;
int c,t,n,d,a[N],f1[N],f2[N],fl[N],fr[N],dp1[N],dp2[N],ans=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)dp1[i]=0,dp2[i]=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		a[n+1]=Inf;a[0]=-Inf;
		for(int i=1,j=1;i<=n;i++){
			while(a[j+1]-a[i]<=d)j++;
			f1[i]=j;
		}
		for(int i=n,j=n;i>=1;i--){
			while(a[i]-a[j-1]<=d)j--;
			f2[i]=j;
		}
		for(int i=1;i<=n;i++){
			fl[i]=0;
			if(f1[f2[i]]>i)continue;
			else fl[i]=fl[f2[i]]+f2[i+1]-f2[i];
			//cout<<i<<":"<<fl[i]<<"\n";
		}
		for(int i=n;i>=1;i--){
			fr[i]=0;
			if(f2[f1[i]]<i)continue;
			else fr[i]=fr[f1[i]]+f1[i]-f1[i-1];
			//cout<<i<<":"<<fr[i]<<"\n";
		}
		for(int i=1;i<=n;i++){
			if(f1[i]<=i+1)continue;
			if(f1[i]!=i)dp1[f1[i]-1]++;
			if(f2[f1[i]-1]==i)dp1[f1[i]-1]+=fl[i];
		}
		for(int i=1;i<=n;i++){
			if(f2[i]>=i-1)continue;
			dp2[f2[i]+1]++;
			if(f1[f2[i]+1]==i)dp2[f2[i]+1]+=fr[i];
		}
		ans=0;
		//for(int i=1;i<=n;i++)cout<<dp1[i]<<" ";cout<<"\n";
		//for(int i=1;i<=n;i++)cout<<dp2[i]<<" ";cout<<"\n";
		for(int i=1;i<n;i++)ans+=dp1[i]*dp2[i+1];
		cout<<ans<<"\n";
	}
	return 0;
}
