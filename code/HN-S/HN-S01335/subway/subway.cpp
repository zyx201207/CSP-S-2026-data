#include<bits/stdc++.h>
using namespace std;
long long NUES,n,m,d,q;
int w[505],t[10000][10000];
int main(){
	cin>>NUES>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int a,b;
			cin>>a>>b;
			t[i][a]=b;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}	
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int k=j+1;k<=m;k++){
				
			}
		}
	} 
	return 0;
} 

