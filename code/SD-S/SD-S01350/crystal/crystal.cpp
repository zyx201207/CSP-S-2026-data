#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int n,m;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int sum=0,ans=0;
	for(int l=1,r=1;r<=n;r++){
		sum+=a[r];
		while((r-l+1)*a[r]-sum>m){
			sum-=a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
