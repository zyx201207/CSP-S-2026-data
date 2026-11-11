#include<bits/stdc++.h>
using namespace std;

int m,n,b,maxx=0;
int a[200010],p[200010],make[200010];

void andd(int x){
	if(x==n){
		b=p[0];
		for(int i=1;i<m;i++){
			b&=p[i];
		}
		if(b>maxx) maxx=b;
	}
	for(int i=0;i<n;i++){
		if(!make[i]){
			p[i]=a[x];
			make[i]=1;
			andd(x+1);
			make[i]=0;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	andd(0);
	cout<<maxx;
	
	return 0;
}
