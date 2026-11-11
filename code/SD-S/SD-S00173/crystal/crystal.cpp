#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5; 
int n;
ll m,ans;
ll a[N],sum[N];
bool check(int l,int r){ //  l-r间是否合法 
	ll v=a[r]*(r-l+1)-(sum[r]-sum[l-1]);
//	cout<<v<<"\n\n";
	if(v<=m) return 1;
	else return 0;
}
void get(int l,int r){
	ll tmp=1e18;
	ll L=l,R=r;
	while(l<=r){
		int mid=(l+r)/2;
	//	cout<<l<<' '<<r<<' '<<mid<<' '<<check(mid,R)<<"\n";
		if(check(mid,R)) r=mid-1,tmp=mid;
		else l=mid+1;
	} 
//	cout<<tmp<<"\n";
//	cout<<R-tmp+1<<"\n";;
	ans=max(ans,R-tmp+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		get(1,i);
	}
	cout<<ans;
	return 0;
}
/*
//  删大样例 

5 5 
1 2 4 8 9

5 8
-3 -1 2 2 7


*/
