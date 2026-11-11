#include<bits/stdc++.h>
using namespace std;
long long n,ans=1,m,z,t,w,q[1000006],a[1000006];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	t=w=1,q[1]=1;
	for(int i=2;i<=n;i++){
		while(t<=w&&(w-t+1)*(a[i]-a[i-1])+z>m) t++,z-=(a[i-1]-a[q[t-1]]);
		z+=(w-t+1)*(a[i]-a[i-1]),q[++w]=i,ans=max(ans,w-t+1);
	}
	cout<<ans;
	return 0;
}