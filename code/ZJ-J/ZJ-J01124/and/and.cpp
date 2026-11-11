#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,a[200010],j,ans,sum,wei[40],f[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=30;i>=0;i--){
		ans=0;
		for(j=1;j<=n;j++){
			if(!f[j])
				if(a[j]&(1<<(i))) ans++;
		}
		if(ans>=m){
			wei[i]=1;
			for(j=1;j<=n;j++)
				if(!(a[j]&(1<<(i)))) f[j]=1;
		}
	}
	for(i=30;i>=0;i--) 
		if(wei[i])sum+=(1<<i);
	cout<<sum;
	return 0;
}