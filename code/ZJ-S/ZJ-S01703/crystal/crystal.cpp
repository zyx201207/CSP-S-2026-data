#include <bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;
int n,m;
int a[N],b[N],cnt,num[N],sum[N],ml,pm[N],ans;
signed main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	num[++cnt]=1;
	b[cnt]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			num[++cnt]=1;
			b[cnt]=a[i];
		}else{
			num[cnt]++;
		}
	}
	ml=cnt;
	pm[cnt]=m;
	sum[cnt]=num[cnt];
	while(ml>1&&(pm[cnt]>=(b[cnt]-b[ml-1])*num[ml-1])){
		pm[cnt]-=(b[cnt]-b[ml-1])*num[ml-1];
		sum[cnt]+=num[ml-1];
		ml--;
	}
	if(ml>1)ans=max(ans,sum[cnt]+pm[cnt]/(b[cnt]-b[ml-1]));
	else{
			ans=max(ans,sum[cnt]);
		}
	for(int i=cnt-1;i>=1;i--){
		if(ml<=i){
			sum[i]=sum[i+1]-num[i+1];
			pm[i]=pm[i+1]+(b[i+1]-b[i])*sum[i];
		}
		else{
			sum[i]=num[i];
			pm[i]=m;
			ml=i;
		}
		while(ml>1&&(pm[i]>=(b[i]-b[ml-1])*num[ml-1])){
		pm[i]-=(b[i]-b[ml-1])*num[ml-1];
		sum[i]+=num[ml-1];
		ml--;
		}
		//cout<<sum[i]<<"<<"<<pm[i]<<"\n";
		if(ml>1){ans=max(ans,sum[i]+pm[i]/(b[i]-b[ml-1]));}
		else{
			ans=max(ans,sum[i]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}