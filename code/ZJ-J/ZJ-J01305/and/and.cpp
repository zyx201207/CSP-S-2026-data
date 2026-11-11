#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long h[33];
long long ap[200009][33];
long long ss[200009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	h[0]=1;
	for(int i=1;i<=30;i++){
		h[i]=h[i-1]*2;
	}
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		long long w;
		scanf("%lld",&w);
		long long o=0;
		while(w){
			if(w%2){
				ap[i][o]=1;
			}else{
				ap[i][o]=0;
			}
			o++;
			w/=2;
		}
		ss[i]=1;
	}
	long long pp=0;
	for(int i=30;i>=0;i--){
		pp=i;
		long long ans=0;
		for(int j=1;j<=n;j++){
			if(ap[j][i]){
				ans++;
			}
		}
		if(ans>=m){
			break;
		}
	}
	long long sum=0;
	for(int i=pp;i>=0;i--){
		long long ans=0;
		for(int j=1;j<=n;j++){
			if(ap[j][i] && ss[j]){
				ans++;
			}
		}
		if(ans>=m){
			for(int j=1;j<=n;j++){
				if(ap[j][i]==0 && ss[j]){
					ss[j]=0;
				}
			}
			sum+=h[i];
		}
	}
	printf("%lld",sum);
	return 0;
}
