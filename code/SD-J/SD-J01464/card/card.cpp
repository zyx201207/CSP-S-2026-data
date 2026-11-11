#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int t[500005];
int las[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=n;
	while(k--){
		for(int i=n-k+1;i<=n;i++){
			if(t[a[i]]==1){
				int dz=0;
				for(int j=1;j<i;j++){
					if(a[j]==a[i]&&a[j]!=-111){
						dz=j;	
						break;
					}
				}
				for(int j=dz;j<=i-1;j++){
					a[i]=-111;
				}
			}
			t[a[i]]=1;
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=-111&&a[i]!=0){
				las[a[i]]++;	
			}
		}
		memset(t,-1,sizeof(t));
	}
	for(int i=1;i<=m;i++){
		cout<<las[i]<<" ";
	}
	return 0;
} 
