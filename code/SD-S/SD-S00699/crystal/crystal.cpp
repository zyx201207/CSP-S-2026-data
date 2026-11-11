#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+5;
int n,m;
int a[N];
int r=-0x3f3f3f3f3f3f3f3f,l=0x3f3f3f3f3f3f3f3f;
int maxx;
bool check(int mid){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]<mid){
			sum+=mid-a[i];
		}
	}
	return sum<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=l){
			maxx++;
		}
	}cout<<maxx;
	return 0;
}

