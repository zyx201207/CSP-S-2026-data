#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		map<int,int> ma;
		int v[500010],tot=0;
		for(int j=i;j<=n;j++){
			if(!ma[a[j]]){
				v[++tot]=a[j];
				ma[a[j]]=1;
			}else{
				int t=tot;
				for(int k=1;k<=tot;k++){
					if(v[k]==a[j]){
						tot=k;
						break;
					} 
				}
				for(int k=tot-1;k<=t+1;k++){
					ma[v[k]]=0;
				}
			}	
		}
		for(int j=1;j<=tot;j++){
			ans[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
