#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],diff[500005],tmp[500005],maxx=0;
long long get_cost(long long l,long long r){
	l++;
	long long len=r-l+1;
	return tmp[l]-(tmp[r+1]-tmp[r+2])*(len)-tmp[r+1];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1; i<=n; i++){
		diff[i]=a[i]-a[i-1];
	}for(long long i=n; i>=1; i--){
		tmp[i]=tmp[i+1]+diff[i];
	}for(long long i=n; i>=1; i--){
		tmp[i]=tmp[i+1]+tmp[i];
	}
	long long j=1;
	for(long long i=1; i<=n; i++){
		while(get_cost(i,j)<=m && j<=n){
			maxx=max(maxx,j-i+1);
			j++;
		}
	}cout<<maxx;
	return 0;
}
