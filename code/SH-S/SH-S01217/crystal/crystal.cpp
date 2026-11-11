#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1000]={};
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cha=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=cha)flag=1;
	}
	int ans=0;
	if(!flag){
		for(int i=2;i<=n;i++){
			if(i&1){
				if((i-1)/2*i*cha>m){
					ans=i-1;
					break;
				}
			}
			else{
				if(i/2*(i-1)*cha>m){
					ans=i-1;
					break;
				}
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	else{
		sort(a+1,a+n+1);
		int now=0;
		for(int i=2;i<=n;i++){
			now=0;
			int flag1=1;
			for(int j=i-1;j>=1;j--){
				now+=a[i]-a[j];
				if(now>m){
					ans=max(ans,i-j);
					flag1=0;
					break;
				}
			}
			if(flag1){
				ans=max(ans,i);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
