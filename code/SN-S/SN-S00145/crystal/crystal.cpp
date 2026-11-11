#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ma=1,cnt=0,j=1;
	for(int i=2;i<=n;i++){
		cnt+=(i-j)*(a[i]-a[i-1]);
		while(j+1<=i&&cnt>m){
			cnt-=(a[i]-a[j]);
			j++;
		}
		ma=max(ma,i-j+1);
	}
	cout<<ma;
	return 0;
}
