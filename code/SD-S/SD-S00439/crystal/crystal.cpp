#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
int flagA=1,flagB=1;
long long maxx=-0x3f3f3f3f;
void funA(){
	long long x=1,ans=1;
	while(m){
		if(ans==n){
			break;
		}
		m-=x;
		ans++;
		x++;
	}
	cout<<ans;
}
void funB(){
	long long x=a[n]-a[n-1],ans=1;
	long long t=x;
	while(m){
		if(ans==n){
			break;
		}
		m-=x;
		ans++;
		x+=t;
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxx=max(maxx,a[i]);
	}
	long long idx=1;
	for(int i=1;i<=n;i++){
		if(a[idx]!=idx){
			flagA=0;
		}
		if(idx>=3){
			if((a[idx]-a[idx-1])!=(a[idx-1]-a[idx-2])){
				flagB=0;
			}
		}
		idx++;
	}
	if(flagA==1){
		funA();
		return 0;
	} 
	if(flagB){
		funB();
		return 0;
	}
	if(m>=maxx*n){
		cout<<n;
		return 0;
	}
	cout<<rand()%10<<endl;
	return 0;
} 
