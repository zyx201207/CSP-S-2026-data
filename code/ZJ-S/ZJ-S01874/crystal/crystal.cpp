#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],d[N],ans,sumd[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		sumd[i]=sumd[i-1]+d[i];
	}
	int l=1,r=1,nowcost=0;
	while(l<=r&&r<=n){
		while(r<=n&&nowcost<=m){
			r++;
			nowcost+=d[r]*(r-l);
			if(nowcost<=m)ans=max(ans,r-l+1);
		}
		while(l<=r&&r<=n&&nowcost>m){
			l++;
			nowcost-=sumd[r]-sumd[l-1];
			if(nowcost<=m)ans=max(ans,r-l+1);
		}
	}
	cout<<ans;
	return 0;
}
/*
15:02 100pts
*/