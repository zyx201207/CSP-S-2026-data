#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
long long int a[N],pre[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		long long int flag=pre[i]-pre[i-x];
		if(a[i]*x-flag<=m)return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/
