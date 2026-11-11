#include <bits/stdc++.h>

using namespace std;
long long a[500005];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	bool f=0;
	long long xx;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	xx=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=xx)f=1;
	}
		
	if(f==0){
		for(int i=1;i<=5e5;i++){
			if((xx+i*xx)*i/2.0>m){
				cout<<i;
				return 0;
			}
		}
		return 0;
	}
	
	int ans=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long al=m;
		int sum=0;
		for(int j=i-1;j>=1;j--){
			if(al-(a[i]-a[j])>=0){
				al-=(a[i]-a[j]);
				sum++;
			}else{
				break;
			}
		}
		ans=max(ans,sum+1);
	}
	cout<<ans;
	return 0;
}
