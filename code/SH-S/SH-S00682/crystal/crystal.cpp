#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=5e5+5; 
ll n,m,a[N],s[N];
bool check(int k){
	for(int i=k;i<=n;i++)
		if(a[i]*k-(s[i]-s[i-k])<=m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
