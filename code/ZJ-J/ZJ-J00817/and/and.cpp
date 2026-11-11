#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,x,j,ans,fl,cnt,sum[35],f[200010][35],g[200010];
main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>x;
		for(j=0;j<=30;j++)
			if((1<<j)&x)
				f[i][j]=1,sum[j]++;
	}
	for(j=30;j>=0;j--){
		if(sum[j]<m)continue;
		if(!fl){
			fl=1;
			for(i=1;i<=n;i++)
				if(f[i][j])g[i]=1;
			ans+=(1<<j);
		}
		else{
			cnt=0;
			for(i=1;i<=n;i++)
				if(f[i][j]&&g[i])cnt++;
			if(cnt<m)continue;
			for(i=1;i<=n;i++)
				if(g[i]&&(!f[i][j]))g[i]=0;
			ans+=(1<<j);
		}
	}
	cout<<ans;
	return 0;
}