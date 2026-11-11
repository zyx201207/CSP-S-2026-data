#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010],c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0){
				for(int l=b[a[j]];l<j;l++){
					b[a[l]]=0;
				}
			}
			b[a[j]]=j;
		}
		for(int i=1;i<=m;i++){
			if(b[i]>0){
				c[i]++;
			}
			b[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}