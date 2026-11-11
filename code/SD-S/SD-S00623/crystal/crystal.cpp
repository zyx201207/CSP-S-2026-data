#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,m;
long long a[5*100005];
long long b[5*100005],s[5*100005];
long long maxx=-1e18;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		b[i]=a[n]-a[i];
	}
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+b[i];
	}
	long long l=1,r=1;
	while(l<=n&&r<=n){
//		cout<<l<<" "<<r<<" "<<s[r]<<" "<<s[l-1]<<" "<<b[r]<<'\n';
		if(s[r]-s[l-1]-(r-l+1)*b[r]<=m){
			maxx=max(maxx,r-l+1);
			r++;
		}
		else{
			l++;
		}
	}
	cout<<maxx;
	return 0;
}
