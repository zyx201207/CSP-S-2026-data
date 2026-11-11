#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[6000],b[4000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int c[6000],x=1;
		for(int j=i;j<=n;j++){
			int f=1;
			for(int k=1;k<=n;k++){
				if(a[j]==c[k]){
					for(int l=k;l<=n;l++){
						c[l]=0;
					}
					c[k]=a[j];
					x=k+1;
					f=0;
					break;
				}
			}
			if(f==1){
				c[x]=a[j];
				x++;
			}
		}
		for(int o=i-1;o<=x;o++){
			cout<<c[o];
		}
		cout<<" ";
		for(int t=i-1;t<=x;t++){
			b[c[t]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" "; 
	}
}
