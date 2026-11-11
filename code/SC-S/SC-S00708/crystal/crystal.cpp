#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int INF=1e18;
const int N=1e6+6;

int n,m;
int a[N],pre[N];

inline bool check(int x){
	int mn=INF;
	for(int i=x;i<=n;i++){
		int need=pre[i]-pre[i-x]-(i-x)*(a[i]-a[i-x]);
		mn=min(mn,need);
	}
	return mn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;pre[1]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+1+n,[](const int &a,const int &b){
		return a<b;
	});
	
	for(int i=2;i<=n;i++) pre[i]=pre[i-1]+(i-1)*(a[i]-a[i-1]);
	
//	for(int i=1;i<=n;i++) cout<<pre[i]<<" ";
	
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	
	return 0;
}
/*
5 5
1 2 4 8 9

3


5 8
-3 -1 2 2 7

4


8 10
-3 0 1 2 3 4 4 8


*/