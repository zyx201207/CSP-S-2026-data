#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1;
bool flaga=0,flagb=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i>=2&&a[i]-a[i-1]!=1) flaga=1;
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flagb=1;
	}
	if(!flaga){
		long long k=1,cnt=0;
		while(cnt<n){
			if(m-k<0) break;
			m-=k;
			cnt++;
			k++;
			ans++;
		}
		printf("%lld",ans);
		return 0;
	}
	if(!flagb){
		long long k=a[2]-a[1],t=a[2]-a[1],cnt=0;
		while(cnt<n){
			if(m-k<0) break;
			m-=k;
			k+=t;
			ans++;
			cnt++;
		}
		printf("%lld",ans);
		return 0;
	}
	return 0;
} 
