#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[300001],mo[500001],ji;
bool biao[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ji=i;
		for(int j=i;j<=n;j++){
			mo[j]=a[j];
			if(biao[mo[j]]){
				for(int k=ji;k<j;k++){
					mo[k]=0;
				}
				ji=j;
			}
			biao[mo[j]]=true;
		}
		for(int j=1;j<=n;j++){
			biao[j]=false;
		}
		for(int j=ji;j<=n;j++){
			cout<<mo[j]<<endl;
			ans[mo[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
