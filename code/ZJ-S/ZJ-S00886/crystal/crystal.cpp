#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,t,w,i,ans,s,a[500010],b[500010],c[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<n;i++)b[i]=a[i+1]-a[i],c[i]=c[i-1]+b[i];
	t=w=1;
	while(w<=n){
		if(s<=m){
			ans=max(ans,w-t+1);
			w++;
			s+=b[w-1]*(w-t);
		}
		else{
			t++;
			s-=c[w-1]-c[t-2];
		}
	}
	cout<<ans;
	return 0;
}
