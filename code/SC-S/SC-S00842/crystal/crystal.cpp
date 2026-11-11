#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],b[N],p[N];
int n,m;
bool check(int len){
	for(int i=1;i<=n-len+1;i++)
		if(p[i+len-1]-(b[i+len-1]-b[i-1])*(i-1)-p[i-1]<=m)	return 1;
	return 0;
}
int find(int l,int r){
	if(l>=r)	return l;
	int mid=(l+r+1)/2;
	if(check(mid))	return find(mid,r);
	else	return find(l,mid-1);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];	
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)	b[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++)	p[i]=b[i]*(i-1)+p[i-1];
	for(int i=1;i<=n;i++)	b[i]+=b[i-1];
	cout<<find(1,5e5);
	return 0;
}