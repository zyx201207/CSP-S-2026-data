#include<bits/stdc++.h>
using namespace std;
long long a[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,minn=0x3f3f3f3f,t=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			c[i]+=a[i]-a[j];
		}
	}
	for(int i=n;i>=1;i--){
		minn=min(abs(c[i]-m),minn);
	}
	for(int i=n;i>=1;i--){
		if(abs(c[i]-m)==minn){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
