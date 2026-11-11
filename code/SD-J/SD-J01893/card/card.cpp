#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],z=0,b[500005]={0},d=1,c[500005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		d=1;
		for(int j=i;j<=n;j++){
			b[d]==a[j];
			for(int l=1;l<=d;l++){
				if(b[d]==b[l]){
					d=l;
				}
			}
			d++;
		}
		for(int f=1;f<=d;f++){
			c[b[f]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
