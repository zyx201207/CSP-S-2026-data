#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+5;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	int l=1; 
	int sum=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		sum+=(i-l)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=a[i]-a[l];
			l++;
		} 
//		cout<<l<<' '<<i<<'\n'; 
		ans=max(ans,i-l+1);
	}
	cout<<ans;  
	return 0;
} 
