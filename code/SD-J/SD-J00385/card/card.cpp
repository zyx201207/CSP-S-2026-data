#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card4.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	vector<int>a(n+1),ans(m+1);
	bool xxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			xxx=1;
		}
	}
	if(n<=500&&m<=200){
		for(int i=1;i<=n;i++){
			vector<int>las(m+1);
			vector<int>bl(n+1);
			for(int j=i;j<=n;j++){
				if(las[a[j]]==0){
					las[a[j]]=j;
				}else{
					for(int k=las[a[j]];k<j;k++){
						if(bl[k]==0){
							bl[k]=1;
							las[a[k]]=0;
						}
					}
					las[a[j]]=j;
				}
			}
			for(int j=i;j<=n;j++){
			if(bl[j]==0){
			ans[a[j]]++;
			if(a[j]==1){
		//		cout<<i<<" "<<j<<" "<<ans[1]<<"\n";
			}
		}
		}
		}
		for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
		return 0;
	}
		if(xxx==0){
		for(int i=n;i>=1;i--){
			if(a[i]!=a[i-1]){
				ans[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++)
		cout<<ans[a[i]]<<" ";
		return 0;
	}
	return 0;
}
