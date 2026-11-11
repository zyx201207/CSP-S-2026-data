#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500500],c[500500];
bool check(int x){
	int sum=0;
	for (int i=2;i<=x;i++){
		sum+=c[i]*(i-1);
	}
	for (int k=x;k<=n;k++){
		if (sum<=m) return true;
		sum=sum-(a[k-1]-a[k-x])+c[k]*(x-1);
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	int l=0,r=n+1;
	int ans=0;
	while (l<r){
		int mid=l+r>>1;
		if (check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid;
		}
	}
	cout<<ans;
	return 0;
}

