#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[1000000],s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(1+a,1+a+n);
	long long j=m;
	for(long long i=n;i>=2;i--){
		int k=i-1,g=1;
		j=m;
		while(a[i]-a[k]<=m&&j-(a[i]-a[k])>=0&&k>=1){
			j-=(a[i]-a[k]);
			g++;
			k--;
		}
		s=max(s,g);
	}
	cout<<s;
	return 0;
}