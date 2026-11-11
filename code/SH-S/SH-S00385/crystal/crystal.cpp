#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N];
bool check(int x){
	int v=0;
	for(int i=1;i<=x;i++){
		v+=(a[x]-a[i]);
	}
	if(v<=m) return true;
	for(int i=x+1;i<=n;i++){
		int p=a[i]-a[i-1];
		v=v+(x-1)*p-(a[i-1]-a[i-x]);
		if(v<=m){
			return true;
		}
	}
	return false;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=0,r=n,mid;
	while(l<r){
		mid=l+r+1>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l<<'\n';
	return 0;
}

