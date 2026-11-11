#include <bits/stdc++.h>
using namespace std;
long long int n,m;
long long int a[500005],b[500005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		long long int j=i;
		while(j<=n){
			b[j]=a[j];
			c[b[j]]++;
			int flag=0;
			long long int x=0;
			for(int z=i;z<j;z++){
				if(b[z]==b[j]){
					x=z;
					flag=1;
					break;
				}
			}
			if(flag){
				while(x<j){
					c[b[x]]--;
					b[x]=0;
					x++;
				}
			}
			j++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}