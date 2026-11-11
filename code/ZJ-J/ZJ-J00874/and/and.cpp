#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,i,k,x,s,t,ans,f[200010],a[200010],
b[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(k=30;k>=0;k--){
		x=(1<<k);s=0;
		for(i=1;i<=n;i++)
			if(((a[i]&x)>=x)&&!f[i])s++;
		if(s>=m){
			ans+=x;
			for(i=1;i<=n;i++)
				if((a[i]&x)<x)f[i]=1;
		}
	}
	cout<<ans;
	return 0;
}