#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt[500005],num,maxn=1,r;
long long read(){
	char s=getchar();
	long long f=1,x=0;
	if(s=='-'){
		f=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+s-'0';
		s=getchar();
	}
	return x*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=0;i<n;i++){
		cnt[i]=a[i+1]-a[i];
	}
	r=n;
	for(int i=n-1;i>=1;i--){
		
		num+=a[r]-a[i];
		while(num>m){
			num-=cnt[r-1]*(r-i);
			r--;
		}
		maxn=(maxn>(r-i+1))?maxn:(r-i+1);
	}
	printf("%lld",maxn);
}