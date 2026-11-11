#include<bits/stdc++.h>
using namespace std;
int n,m,d[600010],l[600001],mp[600001],a[600001],lst[600001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(lst[a[j]]==0){
				lst[a[j]]=j;
			}else{
				for(int k=lst[a[j]];k<=j-1;k++){
					l[k]=1;
					lst[a[k]]=0;
				}
				lst[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(l[j]==0){
				mp[a[j]]++;
			}
		}
		for(int i=1;i<=n;i++){
			lst[i]=0;
			l[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
	return 0;
}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			mp[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
	return 0;
}
