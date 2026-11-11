#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int a[500010]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m>100000000){
		sort(a+1,a+1+n);
		long long ans=int(sqrt(m));
		while((a[1]+a[ans])*ans/2<=m)ans++;
		cout<<ans;return 0;
	}
	sort(a+1,a+1+n,greater<int>());
	int ans=1;
	for(int i=1;i<=n;i++){
		long long m1=m;int ans1=1;
		for(int j=i+1;j<=n;j++){
			if(m1+a[j]>=a[i]){
				ans1++;
				m1-=(a[i]-a[j]);ans=max(ans,ans1);
			}
			else{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
