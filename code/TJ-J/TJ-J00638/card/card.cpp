#include<bits/stdc++.h>
using namespace std;
int ans[500005];
int used[300005]; 
int ca[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ca[i];
	}
	for(int o=1;o<=n;o++){
		for(int i=1;i<=m;i++){
			used[i]=0;
		}
		for(int i=o;i<=n;i++){
			int c=ca[i];
			if(used[c]==0) used[c]=i;
			else{
				for(int j=used[c];j<=i;j++){
					used[ca[j]]=0;
				}
				used[c]=i;
			}
		}
		for(int i=1;i<=m;i++){
			if(used[i]!=0){
				ans[i]++;
			}
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}











