#include<bits/stdc++.h>
#define int long long
//#define pi pair<int,int>
using namespace std;
const int mx=5e5+5;
int n,m,a[mx],s[mx];
bool check(int x){
	for(int i=x;i<=n;i++){
		int x1=s[i]-s[i-x];
		int x2=a[i]*x;
		if(x2-x1<=m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal4.in","r",stdin);
//	freopen("q.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<r;
	return 0;
}