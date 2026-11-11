#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[10010],k[10010],ct[10010],ans[10010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int num=1;
		for(int j=i;j<=n;j++){
			if(ct[a[j]]==0){
				ct[a[j]]=num;
				k[num]=a[j];
				num++;
			}else{
				num=ct[a[j]];
				k[num]=a[j];
				num++;
				ct[a[j]]=0;
			}
		}
		for(int j=1;j<num;j++){
			cout<<k[j]<<" ";
			ans[k[j]]++;
		}
		for(int j=1;j<=n;j++){
			ct[j]=k[j]=0;
		}
		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
