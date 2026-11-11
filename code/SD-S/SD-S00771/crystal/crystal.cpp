#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ma=-1,c,s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=2;i<=n;i++){
		c=0,s=0;
		for(int j=i;j>=1;j--){
			if(s+a[i]-a[j]>m)break;
			s=s+a[i]-a[j];
			c++;
		}
		ma=max(ma,c);
	}
	cout<<ma;
	return 0;
} 
