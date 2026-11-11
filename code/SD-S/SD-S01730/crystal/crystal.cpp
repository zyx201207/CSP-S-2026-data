#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	bool ff=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		if(i>1&&a[i]<a[i-1]) ff=0;
	}
	if(!ff){
		sort(a+1,a+n+1);
	}
	
	int l=0,cnt=0;
	long long sum=0;
	for(int i=1;i<=n;i++){
		long long add=(a[i]-a[i-1])*(long long)(i-l-1);
		sum+=add;
		if(sum>m){
			while(sum>m&&l<i){
				sum-=(a[i]-a[++l]);
			}	
		}
		cnt=max(cnt,i-l);
	}
	printf("%d",cnt);
	return 0;
} 
