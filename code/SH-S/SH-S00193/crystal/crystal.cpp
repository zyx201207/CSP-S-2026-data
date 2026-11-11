#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],b[500005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=1,g=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f=0;
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])g=0;
	}
	if(f){
		long long sum=m;
		ans=1;
		for(int j=1;j<n;j++){
			if(sum>=j){
				sum-=j;
				ans++;
			}
			else break;
		}
		cout<<ans;
		return 0;
	}
	if(g){
		long long sum=m,cha=a[2]-a[1];
		ans=1;
		for(int j=1;j<n;j++){
			if(sum>=j*cha){
				sum-=j*cha;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long sum=m,cnt=1;
		for(int j=i-1;j>=1;j--){
			if(sum>=a[i]-a[j]){
				sum-=(a[i]-a[j]);
				cnt++;
			}
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
