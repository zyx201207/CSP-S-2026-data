#include<bits/stdc++.h>
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n][n]={},b[n]={},c[n]={},d[n]={};
	for(int i=0;i<n;i++){
		cin>>b[i];
		c[i]=i+1;
	}
	for(int x=0;x<n;x++){
		for(int i=0;i<n;i++){
			a[x][i]=b[i];
			for(int j=0;j<i;j++){
				if(a[x][j]==b[i]&&b[i]!=0){
					for(int q=0;q<i;q++){
						
						a[x][q]=0;
					}
					break;
				} 
			}
		}
		b[x]=0;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			//cout<<a[i][j];
			for(int q=0;q<n;q++){
				if(a[i][j]==c[q]){
					b[q]++;
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<b[i]<<" ";
	}
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	return 0;
} 
