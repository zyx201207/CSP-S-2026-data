#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			for(int k=1;k<j;k++){
				if(b[k]==b[j]){
					for(int t=k;t<j;t++){
						b[t]=-1;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(b[j]==k){
					c[k]++;
					b[j]=0;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
