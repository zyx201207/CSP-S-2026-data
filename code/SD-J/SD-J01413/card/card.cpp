#include<bits/stdc++.h>
using namespace std;
int a[500010],flag[300010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			flag[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(flag[a[j]]==0){
				flag[a[j]]=1;
			}
			else if(flag[a[j]]!=0){
				for(int l=i;l<=j;l++){
					flag[a[l]]=0;
				}
				flag[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(flag[j]!=0){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
