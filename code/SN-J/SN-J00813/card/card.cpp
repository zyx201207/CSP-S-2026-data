//SN-J00813 西安翱翔中学 唐子璇 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	long long a[500001][2],b[300001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][1];
		a[i][2]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int u=j+1;u<=n;u++){
				if(a[j]==a[u]){
					for(int x=j;x<=u;x++){
						a[x][2]=0;
					}
					j=u;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(a[j][2]==1){
				b[a[j][1]]+=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
