#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int a[N];
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
	int l=1,ans=0,sum=0;
	for (int r=1;r<=n;r++){
		sum+=(a[r]-a[r-1])*(r-l);
		while (sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout << ans;
	return 0;
}

