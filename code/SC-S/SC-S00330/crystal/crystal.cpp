#include<bits/stdc++.h>
using namespace std;
#define int long long 
//#define lowbit(x) ((x)&(-(x)))
//#define pnt pair<int,int> 
bool MS;
int a[1000001];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int L=1;
	int res=0,ans=0;
	for(int i=1;i<=n;i++){
		if(i!=1)res=res+(a[i]-a[i-1])*(i-L);
		while(res>m){
			res-=(a[i]-a[L]);
			L++;
		}
		ans=max(ans,i-L+1);
	}
	cout<<ans<<"\n";
}
bool MT;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)solve();
//	cerr<<((&MS)-(&MT))/(1024.0*1024.0)<<" MB\n"<<clock()/1000.0<<"s Time";
}
/*
5 8
-3 -1 2 2 7


*/