#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ll long long 
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	ll rt=0;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
		rt+=a[i];
	}
	ll f=rt/2;
	int t=0;
	int  r=n;
	ll gsr=0,gsl=0;
	ll temp=0;
	for(int i=1;i<=n;i++){
		temp+=a[i];
		if(temp>=f){
			t=i;
			break;
		}
	}	
	char t2=a[n],tl;
	ll res=0;
	for(int i=1;i<=t;i++){
		if(gsl+a[i]>f){
			gsl=f;
		}else gsl+=a[i];
		tl=c[i];
		while(gsr<gsl){
			if(gsr+a[r]>gsl){
				if(c[r]!=tl)res+=gsl-gsr;
				a[r]-=gsl-gsr;
				gsr=gsl;
				break;
			}
			if(c[r]!=tl)res+=a[r];
			gsr+=a[r];
			a[r--]=0;
		}
	}
	printf("%lld",res);
	return 0;
} 
