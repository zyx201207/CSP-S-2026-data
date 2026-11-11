#include<bits/stdc++.h>
#define int long long
using namespace std;
int j,n,m,i,a[200010],f[200010],sum,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=30;i>=0;i--){
		sum=0;
		for(j=1;j<=n;j++)
			if(a[j]&(1<<i)&&!f[j])sum++;
		if(sum>=m){
			ans+=(1<<i);
			for(j=1;j<=n;j++)
				if((a[j]&(1<<i))==0)f[j]=1;
		}
	}
	cout<<ans;
	return 0;
}

