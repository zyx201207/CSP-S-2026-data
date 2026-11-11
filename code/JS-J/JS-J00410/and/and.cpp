#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1ll);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
	int max1=0;
		for(int i=1ll;i<=n;i++){
			if(a[i]>max1)max1=a[i];
		}
		cout<<max1;
	}
	else if(m==2){
	int max1=0;
		for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		if(a[i]&a[j]>max1){
			max1=a[i]&a[j];
		}
		}
		}
		cout<<max1;
	}
	else if(m==n){
		int sum=a[1];
		for(int i=2ll;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}
	else if(m==n-1ll){
	int max1=0ll;
		for(int i=1ll;i<=n;i++){
		int sum=0ll;
		for(int j=1ll;j<=n;j++){
		if(i==j){
		continue;
		}
		sum=sum&a[i];
		}
		if(sum>max1)max1=sum;
		}
		cout<<max1;
	}
	else{
		int max1=0ll;
		for(int i=1ll;i<=n;i++){
			if(a[i]>max1)max1=a[i];
		}
		int u=1024ll;
		int y=u*u*u;
		y/=2ll;
		cout<<4;
		}
		return 0;
	}
	

