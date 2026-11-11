#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[500005];
bool temp[300005];
int st[300005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(temp[a[j]]==0){
				temp[a[j]]=1;
			}
			else if(temp[a[j]]==1){
				for(int k=1;k<=m;k++){
					temp[k]=0;
				}
				temp[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(temp[j]==1){
				st[j]++;
			}
		}
		for(int k=1;k<=m;k++){
			temp[k]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<st[i]<<' ';
	}
	return 0;
}
