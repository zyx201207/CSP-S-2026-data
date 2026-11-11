#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<long long>a(n+1);
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	vector<long long>p(n+1,0);
	for(long long i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	for(long long r=1;r<=n;r++){
		long long left=1,right=r,best=1;
		while(left<=right){
			if((left+right)/2*a[r]-(p[r]-p[r-(left+right)/2])<=m){
				best=(left+right)/2;
				left=(left+right)/2+1;
			}
			else right=(left+right)/2-1;
		}
		ans=max(ans,best);
		if(ans==n)break;
	}
	cout<<ans;
}//ez的二分
