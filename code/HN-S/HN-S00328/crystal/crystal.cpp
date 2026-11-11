#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+25;
int n,m;
int a[N],s[N];
bool check(int mid){
	int x=0;
	for(int i=1;i<mid;i++){
		x+=a[mid]-a[i];
	}
	if(x<=m)return 1;
	for(int i=mid+1;i<=n;i++){
		x-=a[i-1]-a[i-mid];
		x+=(a[i]-a[i-1])*mid;
		if(x<=m)return 1;
	}
	return 0;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]-a[i-1];
	}
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	cout<<l;
	return ;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
