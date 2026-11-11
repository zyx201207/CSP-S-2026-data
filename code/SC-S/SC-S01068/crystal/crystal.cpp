#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],b[N];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,mid;
		while(l<=r){
			mid=l+(r-l)/2;
			if(a[i]*(i-1-mid+1)-(b[i-1]-b[mid-1])<=m){
				ans=max(ans,(i-1-mid+1+1));
//				cout<<mid<<' '<<i-1<<'\n';
				r=mid-1;
			} else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
(i-1)*a[i]-b[i-1]<=m
*/