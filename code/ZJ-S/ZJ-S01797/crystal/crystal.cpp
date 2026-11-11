#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],ans=0,qz[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		if((x-1)*a[i]-qz[i-1]+qz[i-x]<=m)return 1;
	}
	return 0;
}
signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)qz[i]=qz[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}

