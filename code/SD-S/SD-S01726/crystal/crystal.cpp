#include<bits\stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
long long a[N],sum[N],ans;
long long check(int dx){
	int j;
	long long ret=0;
	for(j=dx;-(sum[dx]-sum[j-1]-(dx-j+1)*a[dx])<=m&&j>=1;j--){
		ret++;
	}
	return ret;
}
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)	sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ans=max(check(i),ans);
	}
	cout<<ans;
	return 0;
}
