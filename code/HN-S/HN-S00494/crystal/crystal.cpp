#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long sum=0,maxx=-1e18;
				for(int k=i;k<=j;k++)maxx=max(maxx,a[k]);
				for(int k=i;k<=j;k++)sum+=maxx-a[k];
				ans=max(ans,sum);
			}
		}
		cout<<ans;
	}else{
		long long d=a[2]-a[1];
		cout<<m/d;
	}
	return 0;
}
