#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[500005],t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		t=1;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=t;k++){
				if(a[j]==c[k]){
					for(int l=k;l<=t;l++){
						c[l]=0;
					}
					t=k-1;
					break;
				}
			}
			t++;
			c[t]=a[j];
		}
		for(int j=1;j<=n;j++){
			b[c[j]]++;
			c[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}