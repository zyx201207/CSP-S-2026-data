#include<bits/stdc++.h>
using namespace std;
int ets(int w){
	int z=0;
	while(w>0){
		z=w%2*10+z;
		w=w/2;
	}
	return z;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x=0,s;
	int a[100001],b[100001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		while(a[i]>0){
			b[i]=b[i]+a[i]%2;
			a[i]=a[i]/2;
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>x){
				x=a[i];
			}
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int y=b[i]&b[j];
				if(ets(y)>x){
					x=ets(y);
				}
			}
		}
	}else if(m==n){
		for(int i=1;i<=n;i++){
			x=x+ets(b[i]&b[i+1]);
		}
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			int y=0;
			for(int j=1;j<=i;j++){
				for(int z=i;z<=n;z++){
					y=b[j]&b[z]&y;
				}
			}
			if(x<ets(y)){
				x=ets(y);
			}
		}
	}else{
		
	}
	cout<<x;
	return 0;
}
