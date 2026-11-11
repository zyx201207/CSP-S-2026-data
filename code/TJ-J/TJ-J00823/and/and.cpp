#include <bits/stdc++.h>
using  namespace std;
int q(int a){
	int q[10000],ii=0,en;
	for(int i=1;a>0;i++){
		if(a/2>0){
			if(a%2==0){
				q[i]=0;
			}else{
				q[i]=1;
			}
			a/=2;
		}else if(a==1){
			q[i]=1;
			a=0;
		}
		ii=i;
	}
	for(int i=ii;i>0;i--){
		en=en*10+q[i];
	}return en;
}
int s(int a,int b){
	int q[10000],i=1,ii;
	a=a+b;
	b=0;
	while(a>0){
		if(a%10==2){
			q[i]=1;
		}else{
			q[i]=0;
		}
		a/=10;
		i++;
		ii=i;
	}
	for(int i=ii;i>0;i--){
		b=q[i]+b*10;
	}return b;
}
int main(){
	int n,m,best=0;
	cin>>n>>m;
	int aa[n+1];
	for(int i=1;i<=n;i++){
		cin>>aa[i];
		aa[i]=q(aa[i]);
	}
	for(int i;i<=n;i++){
		for(int j;j<=n;j++){
			if(i!=j){
				int z=q(aa[i]);
				int x=q(aa[j]);
				int c=s(z,x);
				if(c>best){
					best=c;
				}
			}
		}
	}
	int end=0;
	int g=1;
	while(best>0){
		end+=best%10*g;
		best/=10;
		g*=2;
	}cout<<end;
	return 0;
}
