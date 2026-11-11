#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+10;
int n,m;
int a[N];
int sum[N];
bool check(int i,int mid){ return a[i]*(mid-i)-sum[mid]+sum[i]<=m; }

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,greater<>());
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	
//	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//	cout<<"\n";
	
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i+1,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(check(i,mid)) l=mid;
			else r=mid-1;
		}
		ans=max(ans,l-i+1);
//		cout<<i<<" "<<l<<"\n";
	}
	cout<<ans;
	return 0; 
}
