#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],b[N],c[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	int l=1,ans=0,sum=0;
	for(int i=1;i<n;i++){
		sum+=(i-l+1)*b[i];
		//cout<<b[i]<<' ';
		while(sum>m && l<i){
			sum-=a[i+1]-a[l];
			l++;
		}
		if(l<=i && sum<=m)ans=max(ans,i-l+1);
	}
	cout<<ans+1<<'\n';
	
	return 0;
}