#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
int n,m;
int a[N];
int sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int mid;
		while(l<r){
			mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){//true
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		maxx=max(maxx,i-l+1);
	}
	cout<<maxx;
	return 0;
}
/*
15min killed I'm good.
*/