#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
int b[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i]; 
	}
	int sum=1;
	for (int i=2;i<=n;i++){
		int l=1,r=i,mid=0,ans=0;
		while (l<=r){
			mid=(l+r)/2;
			if (a[i]*(i-mid)-(b[i-1]-b[mid-1])<=m){
				ans=i-mid+1;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		sum=max(sum,ans);
	}
	cout << sum;
	return 0;
}
