#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
//#define popcnt __builtin_popcount
const int N=5e5+5;
int k;
int n,a[N],m; 
int d[N],s[N]; 
void solve(){
  
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	s[0]=0;
	//vector<int>v; 
	for(int i=1;i<=n;i++)d[i]=a[i]-a[i-1],s[i]=s[i-1]+d[i]*(i-1);
	int ans=0;
	for(int i=1;i<=n;i++){
		int pos=upper_bound(s+1,s+n+1,s[i-1]+m)-s-1;
	//	cout<<i<<" "<<pos<<endl; 
		ans=max(ans,pos-i+1); 
//		if(313323+i==pos)cout<<s[pos]<<" "<<pos<<" "<<a[pos+1]-a[pos]<<endl;
	}
	
	cout<<ans<<endl; 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
/*
hack1:
12 8
-3 -3 -1 -1 0 0 1 1 1 2 3 3
*/
