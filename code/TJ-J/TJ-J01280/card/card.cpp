#include <bits/stdc++.h>
using namespace std;
long long p[500005],q[300005],k[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long m,n;
	cin>>m>>n;
	for(long long i=1;i<=m;i++){
		cin>>p[i];
		q[i]=i;
	}
	for(long long i=1;i<=m;i++){
		for(long long j=i;j<=m;j++){
		    if(p[j]==p[i]){
		    	for(long long l=i;l<j;l++){
		    		q[l]--;
				}
				
			}
	    }
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			if(p[j]==i){
				k[i]+=q[j];
			}
		}
	}
	for(long long i=1;i<=n;i++){
		cout<<k[i]<<" ";
	}
	return 0;
}
