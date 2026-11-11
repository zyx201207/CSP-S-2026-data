#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=5e5+10;
int a[N];
int sum;
int l=1;
int ans;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int spend=(i-l)*a[i]-sum;
		if(spend>m){
			for(;l<i;l++){
				sum-=a[l];
				if(((i-1)-(l+1)+1)*a[i]-sum<=m){
					l++;
					break;
				}
			}
		}
		sum+=a[i];
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
//crystal by 王梓凡 SN-00702
//完成于[15:17] 
