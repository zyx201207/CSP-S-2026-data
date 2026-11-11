#include<bits/stdc++.h>
using namespace std;
long long n,z[500005],f[500005],ans,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>z[i];
	}
	sort(z+1,z+n+1);
	for(long long i=2;i<=n;i++){
		f[i]=f[i-1]+(z[i]-z[i-1])*(i-1);
	}
	long long l=1,r=1;
	for(;r<=n;r++){
		while(l<=r&&f[r]-(f[l-1]+(l-1)*(z[r]-z[l-1]))>m){
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/