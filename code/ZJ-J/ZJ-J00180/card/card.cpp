#include<bits/stdc++.h>
using namespace std;
int a[200005];
int tong[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>500){	
		int ji=1;
		for(int i=1;i<=n;i++){
			
			if(a[i]!=ji){
				cout<<i-1<<" ";
				ji++;
				i--;
			}
		}
		return 0;
	}
	map<int,bool>mp;
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++)mp[i]=0;
		
		for(int j=i;j<=n;j++){
			
			if(mp[a[j]]==0)mp[a[j]]=1;
			else{
				int id=0;
				for(int z=i;z<=j;z++){
					if(a[z]==a[j]){
						id=z;
						break;
					}
				}
				for(int z=id;z<=j;z++){
					mp[a[z]]=0;
				}
				mp[a[j]]=1;
			}
		}
		set<int> s;
		for(int j=1;j<=n;j++){
			if(mp[a[j]]==1){
				tong[a[j]]++;
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	
	return 0;
}