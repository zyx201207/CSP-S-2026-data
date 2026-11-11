#include<bits/stdc++.h>
using namespace std;

int ans[300005],a[500005],d[500005];
int n,m;

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	memset(d,n,0);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			d[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			for(int k=i;k<=n;k++){
				if(j==k)continue;
				if(d[j]==d[k]){
					for(int v=j;v<k;v++){
						d[v]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(d[j]==k)ans[k]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	
	return 0;
} 
