#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+10;
int n,m,a[N][N],c[300010]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i][i];
		int d=i;
		for(int j=i+1;j<n;j++){
			d++;
			if(d<=n)
				a[d][j]=a[i][i];
		}
		for(int k=n-1;k>=i;k--){
			if(a[k][i]==a[i][i]){
				for(int j=k+1;j<=i;j++)
					a[j][i]=0;
				}
		}
		for(int j=0;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int b=a[j][k];
				c[b]+=1;
			}
		}
	}
	for(int i=1;i<=m;i++)
		cout<<c[i]<<" ";
	return 0;
}

