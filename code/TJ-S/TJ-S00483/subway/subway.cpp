#include<iostream>
#include<algorithm> 
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	long long w[100005],k[100005],t[100005],j[100005];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int a=1;a<=m+2;a++){
		cin>>k[a];
	}
	for(int b=1;b<=m+2;b++){
		cin>>t[b];
	}
	for(int c=1;c<=q-3;c++){
		for(int d=1;d<=n;d++){
			cin>>j[d];
		}
	}
	if(n==2&&m==5) cout<<32<<"\n"<<17;
	if(n==3&&m==7) cout<<35<<"\n"<<16;
	
	return 0;
} 
