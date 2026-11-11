#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
int n,m;
int sum[N];
bool check(int x,int y){
	return a[y]*(y-x+1)-(sum[y]-sum[x-1])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1; i<=n; i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for (int i=1; i<=n; i++){
		int l=i+1,r=n;
		while (l<r){
			int mid=(l+r+1)/2;
			if (check(i,mid)){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,l-i+1);
	}
	cout<<ans<<"\n";
	return 0;
}