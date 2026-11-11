#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=5e5+5;
int n,m,a[maxn],b[maxn],ans=0;
bool check(int x){
	for(int i=x;i<=n;i++){
		if(a[i]*x-(b[i]-b[i-x])<=m){
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			ans=mid;
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
