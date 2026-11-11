#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long ll;

int n;
ll m,a[500005],s[500005],b[500005];

bool check(){
	int r=b[2];
	for(int i=3;i<=n;i++){
		if(b[i]!=r) return 0;
	}
	return 1;
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i],b[i]=a[i]-a[i-1];
	if(n<=5000){
		ll ans=1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				ll f=a[j],num=j-i+1,sum=s[j]-s[i-1];
				ll st=f*num,mm=st-sum;
				if(mm<=m){
					ans=max(ans,num);
				}
			}
		}
		printf("%d",ans);
		return 0;
	}
	if(check()){
		ll bb=b[2];
		ll onum=m/bb;
		ll ans=1;
		for(int i=2;i<=n;i++){
			ll c=(i*i-i)/2;
			if(c<=onum) ans=i;
			else break;
		}
		printf("%d",ans);
		return 0;
	}
	
	return 0;
}
//75pts
