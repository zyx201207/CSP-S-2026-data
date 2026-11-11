#include<bits/stdc++.h>
using namespace std;
int a[510000];
int ans[510000];
vector<int>table;
bool shou[510000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5&&m<=2){
		if(m==1){
			for(int i=1;i<=n;i++){
				for(int j=0;j<table.size();j++){
					if(table[j]==a[i]&&shou[j+1]==0){
						shou[j]=1;
						int b=j;
						while(b<=table.size()){
							shou[b+1]=1;
							b++;
						}
						table.push_back(a[i]);
					}
					else{
						table.push_back(a[i]);
					}
				}
				for(int k=0;k<table.size();k++){
					if(table[k]==a[i]&&shou[k+1]==0) ans[i]++;
				}
			}
			for(int p=1;p<=m;p++){
				cout<<ans[p]<<" ";
			}
		}
		else if(m==2){
			for(int i=2;i<=n;i++){
				for(int j=0;j<table.size();j++){
					if(table[j]==a[i]&&shou[j+1]==0){
						shou[j]=1;
						int b=j;
						while(b<=table.size()){
							shou[b+1]=1;
							b++;
						}
						table.push_back(a[i]);
					}
					else{
						table.push_back(a[i]);
					}
				}
				for(int k=0;k<table.size();k++){
					if(table[k]==a[i]&&shou[k]==0) ans[i]++;
				}
			}
			for(int p=1;p<=m;p++){
				cout<<ans[p]<<" ";
			}
		}
	}
	
	return 0;
}
