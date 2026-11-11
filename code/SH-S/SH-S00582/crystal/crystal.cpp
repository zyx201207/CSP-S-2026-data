#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,inf=1e12+10;
int n,m,a[N],pr[N],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=inf;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pr[i]=pr[i-1]+a[i];
		//cout<<pr[i]<<" ";
	}
	//cout<<"\n";
	int j;
	for(int i=1;i<=n;i++){
		//cout<<ans<<"\n";
		j=i+ans;
		if(j>n)continue;
		if((j-i+1)*a[j]-(pr[j]-pr[i-1])<m){
			while((j-i+1)*a[j]-(pr[j]-pr[i-1])<=m&&j<=n){
				j++;
			}
			ans=j-i;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

*/
