#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[3000005],b[3000005];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		long long c[n+1]={0};
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0) c[a[j]]=1;
			else{
				for(int sd=1;sd<=j;sd++){
					if(a[sd]==a[j]){
						c[sd]=0;
						for(int sdf=sd;sdf<=n;sdf++) c[sdf]=0;
					}
				}
			}
		}
		for(int j=1;j<=n;j++) if(c[j]==1) b[a[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
