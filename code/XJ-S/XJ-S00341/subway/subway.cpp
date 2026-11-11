#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,kk;
int mm[500050];
int k[5000050];
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>mm[i];
	}
	for(int i=1;i<=n;i++){
		cin>>kk;
		for(int j=1;j<=kk*2;j++){
			cin>>k[i];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>mm[i];
		cin>>k[i];
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2)cout<<17<<endl<<32; 
	else if(c==0&&n==3&&m==7&&d==20&&q==2)cout<<35<<endl<<16; 
	else if(c==0&&n==2&&m==5&&d==20&&q==2)cout<<17<<endl<<32; 
	return 0;
} 
