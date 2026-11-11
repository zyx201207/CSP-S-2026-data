#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	int c=0;
	for(int i=1;i<=n;i++){
		c=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=c;k++){
				if(b[k]==a[j]){
					for(int l=k;l<=c;l++){
						b[l]=0;
					}
					c=k-1;
					break;
				}
			}
				c++;
			    b[c]=a[j];
		}
		for(int j=1;j<=c;j++){
			for(int k=1;k<=m;k++){
				if(b[j]==k){
					d[k]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	cout<<endl;
	return 0;
}
