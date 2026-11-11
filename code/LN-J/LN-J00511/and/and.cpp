#include<bits/stdc++.h>
using namespace std;
long long a,b;
long long x[200010];
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(long long i=1;i<=a;i++){
		cin>>x[i];
	}
	long long MAXN=-1;
	if(b==2){
		long long c=0;
		for(long long i=1;i<=a;i++){
			for(long long j=1;j<=a;j++){
				if(i==j){
					continue;
				}
				c=x[i]&x[j];
				MAXN=max(MAXN,c);
			}
		}
	}else if(b==1){
		for(long long i=1;i<=a;i++){
			MAXN=max(MAXN,x[i]);
		}
	}else if(b==a){
		MAXN=x[1];
		for(long long i=2;i<=a;i++){
			MAXN=MAXN&x[i];
		}
	}else if(b==a-1){
		long long c=0;
		for(long long i=1;i<=a;i++){
			if(i==1){
				c=x[2];
			}else{
				c=x[1];
			}
			for(long long j=1;j<=a;j++){
				if(j==i){
					continue;
				}
				c=c&x[j]
			}
		}
	}
	cout<<MAXN;
	return 0;
}
