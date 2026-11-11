#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long maxn=-999999;
long long f[500005],a[500004];
int main(){ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		int num=1;
		int m1=m;
		for(int j=i-1;j>=1;j--){
			if(m1>=(a[i]-a[j])){
				num++;
				m1-=(a[i]-a[j]);
			}
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}
