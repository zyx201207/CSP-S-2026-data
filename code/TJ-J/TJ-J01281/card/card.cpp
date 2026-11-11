#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=0;
	while(n){
		for(int j=1;j<=n;j++){
			b[j]=a[i+j];
			for(int k=1;k<j;k++){
				if(b[k]==b[j]){
					for(int h=k+1;h<=j;h++){
						b[h]=0;
					}
				}
			}	
		}
		for(int s=1;s<=m;s++){
			for(int j=1;j<=n;j++){
				if(b[j]==s){
					c[s]++;
				}
			}
		}
		i++;
		n--;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
