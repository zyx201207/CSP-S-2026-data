#include<bits/stdc++.h>
using namespace std;
long long a[200010],tb[200010],ans[200010];
int find(int u,int pos){
	for(int i=1;i<=u;i++){
		if(tb[i]==pos){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(find(j,a[j])==-1){
				tb[j]=a[j];
			}
			else{
				for(int k=find(j,a[j]);k<j;k++){
					tb[k]=-1;
				}
				tb[j]=a[j];
			}
		}
		for(int j=1;j<=n;j++){
			if(tb[j]!=0&&tb[j]!=-1){
				ans[tb[j]]++;
			}
		}
		memset(tb,0,sizeof(tb));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
