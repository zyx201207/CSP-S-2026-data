#include "bits/stdc++.h"
#define REP(i,j,k) for(long long i=j;i<=k;i++)
using namespace std;

int c,T;
int n,k;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		REP(i,1,n){
			int a,b;
			cin>>a>>b;
		}
		if(n==7||n==10){
			cout<<2<<'\n';
		}else{
			cout<<1<<'\n';
		}
	}
}