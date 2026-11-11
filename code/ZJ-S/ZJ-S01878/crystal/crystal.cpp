#include<bits/stdc++.h>
#define for1(i,x,y,k) for(int i=x;i<=y;i+=k)
#define for2(i,x,y,k) for(int i=x;i>=y;i-=k)
#define int long long
#define pb push_back
#define pf push_front
#define md (t[p].l+t[p].r>>1)
#define mi (lc+rc>>1)
#define mid (l+r>>1)
#define maotai mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define pii pair<int,int>
using namespace std;
const int N=5e5+5;
int n,m,l=1,r;
int a[N],pre[N];
bool suan(int p){
	int al=0;
	for1(i,1,n-p+1,1){
		int sum=pre[i+p-1]-pre[i-1];
		if(a[i+p-1]*p-sum<=m)
			return true;
	}//iµ½i+p-1 
	return false;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for1(i,1,n,1)
		cin>>a[i];
	r=n;
	sort(a+1,a+n+1);
	for1(i,1,n,1)
		pre[i]=pre[i-1]+a[i];
	while(l<r-1){
		if(suan(mid))
			l=mid;
		else
			r=mid;
	}
	for2(i,r,l,1){
		if(suan(i)){
			cout<<i;
			return 0;
		}
	}
	return 0;
}/*
5 5
1 2 4 8 9
*/
