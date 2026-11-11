#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+6;
int n,d,x[N];
int dp1[N],dp2[N];
int c,t;
int fi1(int s){
	for(int i=s+1;i<=n;i++){
		if(x[i]-x[s]<=d&&x[i]-x[s-1]>d)return i;
		else if(s==1&&x[i]-x[s-1]>d)return i;
	}
	return -1;
}
int fi2(int s){
	if(s==1)return -1;
	for(int i=n;i>=s+1;i--){
		if(x[i]-x[s]<=d&&x[i]-x[s-1]>d)return i;
	}
	return -1;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		dp1[1]=1,dp1[2]=1;
		for(int i=1;i<=n;i++){
			int st=fi1(i),ed=fi2(i);
			//cout<<i<<' '<<st<<' '<<ed<<'\n';
			if(ed!=-1)for(int j=st;j<=ed;j++)dp2[j]+=dp2[i],dp1[j]+=dp1[i];
			if(ed==-1)dp2[st]+=dp1[i];
			//cout<<dp1[i]<<' '<<dp2[i]<<"\n";
		}
		int cnt=0;
		for(int i=1;i<n;i++)if(x[i+1]<=x[i]+d&&x[i+2]>=x[i]+d)cnt++;
		int ans=0;
		for(int i=1;i<=n;i++)ans+=dp2[i];
		for(int i=1;i<=n;i++)dp1[i]=dp2[i]=0;
		cout<<ans<<'\n';
	} 
	return 0;
}

