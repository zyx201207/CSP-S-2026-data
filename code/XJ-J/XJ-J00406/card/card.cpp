#include<bits/stdc++.h>
using namespace std;
long long n,flag=0,m,a[500010],b[500010],t[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		flag=0;
		for(int j=i;j<=n;j++){
			for(int l=i;l<=j;l++){
				if(a[j]==b[l]){
					for(int k=l;k<=n;k++){
						b[k]=0;
					}
				}
				b[j]=a[j];
			}
		}
		for(int j=i;j<=n;j++){
				t[b[j]]++;
			}
			memset(b,sizeof(b),0);
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
}