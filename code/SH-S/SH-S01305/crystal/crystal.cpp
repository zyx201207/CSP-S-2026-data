#include<bits/stdc++.h>
#define int long long
int n,m,a[500005],need[500005],res;
using namespace std;
bool jud(int len){
	for(int l=1;l+len-1<=n;l++){
		int r=l+len-1;
		int cost=need[r]-need[l]-(a[r]-a[l])*(l-1);
		if(cost<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		need[i]=need[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int l=1,r=n;
	//若我让更多的水晶被合成为一个，那我一定能让更少的水晶合成 
	//l,r,mid均为区间长度，即合成的水晶数 
	while(l<=r){
		int mid=(l+r)>>1;
		if(jud(mid)){
			res=mid;
			l=mid+1;
		} 
		else{
			r=mid-1;
		}
	}
	cout << res;
}
