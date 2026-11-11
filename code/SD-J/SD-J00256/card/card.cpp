#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int pop[500005];
		for(int k=i;k<=n;k++) pop[k]=1;
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(a[k]=a[j]&&pop[k]!=-1){
					for(int l=k;l<=j;l++){
						pop[i]=-1;
					}
				}
			}
		}
		for(int k=i;k<=n;k++){
			if(pop[k]==1) ans[a[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

