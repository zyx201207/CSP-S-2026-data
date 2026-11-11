#include<bits/stdc++.h>
using namespace std;
long long a[510000],s[510000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,mx=-1e18;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(long long i=1;i<=n;i++){
		for(long long j=i;j>=1;j--){
			if(j*a[i]-s[i]+s[i-j]<=m){
				mx=max(mx,j);
				break;
			}
		}
	}
	cout<<mx;
	return 0;
}
