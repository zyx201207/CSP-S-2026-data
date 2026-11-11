#include<bits/stdc++.h>
#define ll long long
#define sc scanf
#define pf printf
using namespace std;
int c,t,n,k,u[1000006],v[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	sc("%d%d",&c,&t);
	for(int i=1;i<=t;i++){
		sc("%d%d",&n,&k);
		for(int j=1;j<n;j++){
			sc("%d%d",&u[j],&v[j]);
			u[v[j]]=v[u[j]];
		}
		pf("%d",i);
	}
	return 0;
} 
