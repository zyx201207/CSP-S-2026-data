#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int num[30010];
int x[50050];
int u[50010];
int ans[30010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			u[j]=a[j];
			num[a[j]]++;
			if(num[a[j]]==1){
				x[a[j]]=j;
			}
			if(num[a[j]]==2){
				for(int k=x[a[j]];k<j;k++){
					num[u[k]]=0;
					u[k]=0;
				}
				num[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]+=num[j];
			num[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}