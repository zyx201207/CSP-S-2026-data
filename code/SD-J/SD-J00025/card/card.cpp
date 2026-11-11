#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,s=0,b[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x; 
		b[i]=x;
		for(int j=1;j<i;j++){
			if(b[j]==x){
				for(int k=j;k<i;k++){
					b[k]=0;
				}
			}
			a[b[j]]++;
		}
		a[b[i]]++;		
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<' ';
	}
}
