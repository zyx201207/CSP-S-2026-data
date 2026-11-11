#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i,j,ans,x;
ll m,M,t,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=2;i<=n;){
		M=t=x=0;
		while(a[i+t]==a[i])t++;
		for(j=i-1;j>=1;j--){
			M+=a[i]-a[j];
			if(M>m)break;
			x=i-j;
		}
		x+=t;
		ans=max(ans,x);
		i+=t;
	}
	cout<<ans;
	return 0;
}
