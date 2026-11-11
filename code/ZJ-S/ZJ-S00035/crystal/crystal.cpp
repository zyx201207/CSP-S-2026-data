#include<bits/stdc++.h>
#define N 1000010
#define int long long
using namespace std;
int n,m,r,i,ma,a[N],b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;r=1;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(i=1;i<=n;i++){
		while(r+1<=n&&(a[r+1]*(r-i+2)-b[r+1]+b[i-1])<=m){
			r++;
		}
		ma=max(ma,r-i+1);
	}
	cout<<ma;
}
//by wild cat