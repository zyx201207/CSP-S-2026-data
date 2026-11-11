#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0;
long long a[500005];
int main(){
	freopen("crystal.in ","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		long long z=1,h=m,u=a[i];
		for(int j=i;j<=n;j++){
			long long y=(a[j]-u)*z;
			if(a[j]-u>=0&&y<=h){
				u=a[j];
				h-=y;
				z++;
			}else if(y>h){
				break;
			}
		}
		if(z>cnt){
			cnt=z;
		}
	}
	printf("%lld",cnt);
	return 0;
	
}
