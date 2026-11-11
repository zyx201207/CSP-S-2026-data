#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=5e5+5;
int n,m;
int a[N];

bool check(int x){
	int now=a[x],cnt=0;
	for(int i=1;i<=x;i++){
		cnt+=(now-a[i]);
	}
	for(int i=1;i+x-1<=n;i++){
		if(cnt<=m){
			return true;
		}
		cnt-=(now-a[i]);
		cnt+=(x-1)*(a[i+x]-now);
		now=a[i+x];
	}
	return false;	
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=0,r=n;
	while(l<r-1){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<l;
	return 0;
}
