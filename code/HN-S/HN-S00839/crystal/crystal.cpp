#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 500005
int s[MAXN],n,m;
bool check(int x){
	int q=s[x],sum=0;
	for(int i=1;i<x;i++){
		sum+=(q-s[i]);
	}return sum<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}sort(s+1,s+n+1);
	int l=1,r=n+1,mid;
	while(l+1<r){
		mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}cout<<l;
	return 0;
}
