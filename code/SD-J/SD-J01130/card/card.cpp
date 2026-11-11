#include<bits/stdc++.h>
using namespace std;
int syg[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[500001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int table[300001];
		for(int j=1;j<=m;j++){
			table[j]=0;
		}
		for(int k=i;k<=n;k++){
			if(table[a[k]]==0){
				table[a[k]]=k;
			}else{
				for(int j=1;j<=m;j++){
					if(table[j]>=table[a[k]]) table[j]=0;
				}
				table[a[k]]=k;
			}
		}
		for(int j=i;j<=m;j++){
			if(table[j]) syg[j]++;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<syg[j]<<' ';
	}
	return 0;
}

