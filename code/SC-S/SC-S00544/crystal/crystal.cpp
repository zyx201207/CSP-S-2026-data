#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],k[500010],sum;
int maxx;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		k[i]=a[1]-a[i];
	}
	for(int i=1,j=1;i<=n&&j<=n;i++){//(j-i+1)
		while(j+1<=n&&sum+k[j+1]-(j-i+2)*k[i]<=m){
			j++;
			sum+=k[j];
			maxx=max(maxx,j-i+1);
		}
		sum-=k[i];
	}
	cout<<maxx;
	return 0;
}