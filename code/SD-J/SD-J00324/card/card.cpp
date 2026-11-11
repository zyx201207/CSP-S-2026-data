#include <bits/stdc++.h>
using namespace std;
int c[5000000],d[5000000],s[5000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			d[j]=c[j];
			for(int k=1;k<j;k++){
				if(d[k]==c[j]){
					for(int l=k+1;l<=j;l++){
						d[l]=0;
					}
				}
			}
		}
		for(int h=1;h<=n;h++){
			for(int j=1;j<=m;j++){
				if(d[h]==j) s[j]+=1;
			}
			d[h]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
		return 0;
} 
