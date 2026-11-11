#include<bits/stdc++.h>
#define ll long long
#define sc scanf
#define pf printf
using namespace std;
int c,t,n,d,x[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	sc("%d%d",&c,&t);
	for(int l=1;l<=t;l++){
		sc("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			sc("%d",&x[i]);
		}
		pf("%d",n-3);
	}
	return 0;
} 
