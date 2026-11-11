#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int n,m;
int s[N];
inline bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		int cost=s[i+x-1]-s[i-1];
		int sum=a[i+x-1]*x;
		if(sum-cost<=m)return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
//	cout<<n<<" ";
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		if(n==-36)cout<<i<<" "<<a[i]<<" "<<a[i-1]<<" ";
	}
//	cout<<n<<" ";
	sort(a+1,a+n+1);
//	cout<<1<<endl;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	int ans=0;
//	cout<<n;
	while(l<=r){
		int mid=(l+r)/2;
//		cout<<mid;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
