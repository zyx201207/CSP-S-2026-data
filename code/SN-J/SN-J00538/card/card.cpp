#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005]{0},c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			b[i+sum]=a[j];
			for(int k=1;k<=j;k++){
				if(b[j]==b[k]){
					for(int h=1;h<=j;h++){
						b[h]=0;
					}
					b[1]=a[j];
				}
			}
			sum++;
		}
		for(int f=1;f<=m;f++){
			for(int d=1;d<=n;d++){
				if(b[d]==f){
					c[f]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
