#include<bits/stdc++.h>
using namespace std;
int a[500010],b[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		map<int,int> mp2;
		for(int k=j;k<=n;k++){
			if(mp2[a[k]]==0){
				mp2[a[k]]=j;
			}else{
				int l=mp2[a[k]];
				for(int o=l;o<k;o++){
					mp2[a[o]]=0;
				}
				mp2[a[k]]=k;
			}
			
		}
		for(auto i:mp2){
			if(i.second>0)b[i.first]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}