#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
int a[500005],b[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int l=1,r=n,ans=0;
	while(l<r){
		int mid=(l+r)/2;
		if(1ll*a[mid]*mid-b[mid]<=m){
			ans=mid;
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
