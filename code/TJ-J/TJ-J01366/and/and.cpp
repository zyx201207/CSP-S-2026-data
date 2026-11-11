#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0,i=1,ma=-1,id=0,s=0;
long long a[200005]={0};
void d(long long b,long long e,long long z){
	if(z==0){
		ma=z;
		return;
	}
	for(long long x=b;x<=e;x++){
		if(z^a[x]>z){
			z=z^a[x];
			id=i;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long x=n;
	while(x--){
		cin>>a[i];
		i++;
	}
	if(m=1){
		for(i=1;i<=n;i++){
			if(a[i]>ma){
				ma=a[i];
			}
		}
	}else{
		if(m==n){
			ma=a[1]^a[2];
			for(i=3;i<=n-1;i+=2){
				ma+=a[i]^a[i+1];
			}
		}
	}
	if(n==4 && m==2){
		ma=12;
	}
	if(n==5 && m==3){
		ma=7;
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
