#include<bits/stdc++.h>
using namespace std;	
int a[200005];
int b[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=m;j++){
			if(j!=i && a[j]!=a[j-1]){
				b[a[j-1]]++;
				if(j==m){
					b[a[m]]++;
				}
			}
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<endl;
	}
	return 0;
} 
