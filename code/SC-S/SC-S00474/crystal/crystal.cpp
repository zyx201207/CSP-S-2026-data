#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
#define MUBIAO ios_base::sync_with_stdio(0);
#define CESUO cin.tie(0);
#define frein freopen("crystal.in","r",stdin);
#define freout freopen("crystal.out","w",stdout);
#define mod 998244353
#define inf 1e14
#define pii pair<int,int>
using namespace std;
const int maxn=1e6+10;

int n,m,a[maxn],s[maxn],ans=0;

bool check(int mid,int pos){return (a[pos]*(pos-mid+1)-(s[pos]-s[mid-1])<=m);}

void Solve(int pos){
	int L=1,R=pos,res=-1;
	while(L<=R){
		int mid=(L+R)>>1;
		if(check(mid,pos))R=mid-1,res=mid;
		else L=mid+1;
	}
	ans=max(pos-res+1,ans);
}

signed main(){
	MUBIAO CESUO
	frein freout
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)Solve(i);
	cout<<ans;
	return 0;
}