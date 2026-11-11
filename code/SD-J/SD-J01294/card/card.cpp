#include<bits/stdc++.h>
using namespace std;
int a[5000010],c[3000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	int b[n+10][m+10]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j][i]=a[j];
			for(int k=1;k<=j-1;k++){
				if(b[k][i]==b[j][i]){
					for(int l=k;l<=j-1;l++)	 b[l][i]=-1;
					
				}
			}
		}
	}
	
	for(int i=1;i<=m;i++) c[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				
				if(b[j][i]==k) c[k]++;
			}	
		}
	}
	for(int k=1;k<=m;k++){
		if(k!=m) cout<<c[k]<<' ';
		else cout<<c[k];
	}
	return 0;
} 
