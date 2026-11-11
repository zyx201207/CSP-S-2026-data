#include <bits/stdc++.h>
using namespace std;
long long n,m,a[505000],d[505000],cnt=0;
bool c(long long x,long long y){
	return ((a[x]-a[x-1])*(x-y)-(a[x]-a[y])<=m);
}
long long g(long long x){
	long long y=d[x-1]; 
	while((!c(x,y))&&y<x){
		y++;
	}
	d[x]=y;
	return x-y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	for(long long i=1;i<=n;i++){
		cnt=max(cnt,(long long)g(i));
	}
	cout<<cnt;
	return 0;
}
