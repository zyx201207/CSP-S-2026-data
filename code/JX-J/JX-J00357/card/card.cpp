#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n,m;
long long a[N];
long long pd[N];
int cmp=0;
long long ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(n--){
		memset(pd,0,sizeof(0));
		cmp++;
		for(int i=cmp;i<=n;i++){
			pd[i]=a[i];
			for(int j=1;j<=n and j!=i;j++){
				if(pd[i]==a[j]){
					memset(pd,0,sizeof(0));
					continue;
				}
				else{
					pd[i]=a[j];
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(pd[j]==i){ 
					ans[i]++;
					continue;
				}
			}
		}
		memset(pd,0,sizeof(0));
	}	
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
