#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],b[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=m;i++){
		int c=0;
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[j]==a[k]&&a[j]==i){
					for(int l=1;l<=k;l++)b[l]=0;
				}
			}
			bool pd=0;
			for(int m=1;m<=n;m++)if(b[m]==i)pd=1;
			if(pd)c++;
		}
		cout<<c<<' ';
	}
	return 0;
} 
