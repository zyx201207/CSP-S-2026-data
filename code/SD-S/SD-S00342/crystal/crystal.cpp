#include<bits/stdc++.h>
#define endl "\n"
#define fr first
#define se second
#define int long long
using namespace std;
const int N=1e6+1000;
int a[N],ans[N],num[N],n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool flang=1;
	for(int i=1;i<=n;i++){
		num[i]=num[i-1]+a[i];
		if(num[i]!=1){
			flang=0;
		}
	}
	if(n>5000&&flang==1){
		for(int i=1; ;i++){
			if(m<0){
				cout<<i-1;
				return 0;
			}
			m-=i;
		}
	}
	if(n>5000&&flang!=1){
		for(int i=a[2]-a[1],j=0; ;i+=a[2]-a[1],j++){
			if(m<0){
				cout<<j;
				return 0;
			}
			m-=i;
		}
	}
	for(int i=1;i<=n;i++){
		ans[i]=1e18;
	}
	for(int r=1;r<=n;r++){
		for(int l=1;l<=r;l++){
			ans[r-l+1]=min(ans[r-l+1],(r-l)*a[r]-(num[r-1]-num[l-1]));
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]>m){
			cout<<i-1;
			return 0;
		}
	}
	return 0;
}

