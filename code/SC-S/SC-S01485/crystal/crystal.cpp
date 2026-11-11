#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long m,b[500005],c[500005];
long long a[500005],dp[500005],x[500005];
inline void com(int g){
	long long ct=b[g-1];
	long long i=1;
	if((m-c[g-1])>=b[g-1]) {
		x[g]=x[g-1]+1;
		c[g]+=c[g-1];
		while((c[g-1]+ct)<=m)
		{
			if(i>x[g-1]) break;
			c[g]+=b[g-1];
			ct+=b[g-1];
			++i;}
		dp[g]=max(dp[g-1],i);
	}
	else dp[g]=dp[g-1];
	}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		b[i]=a[i]-a[i-1];
	}
	dp[1]=0;
	c[1]=0;
	x[1]=0;
	for(int i=2;i<=n;i++){
		com(i);
	}
	cout<<dp[n];
	return 0;
}