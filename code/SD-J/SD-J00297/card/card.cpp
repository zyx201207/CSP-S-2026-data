#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],c[200005],num,x[200005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=n,nu=0;
	while(k--){
		nu+=1;
		num=0;
		memset(c,0,sizeof(c));
		for(int i=nu;i<=n;i++){
			for(int j=nu;j<i;j++){
				if(c[j]==a[i]){
					for(int k=j;k<=n;i++){
						if(c[k]==0){
							break;
						}
						else{
							c[k]=0;
							num--;
						}
					}
				}
			}
			c[i]=a[i];
			num++;
		}
		for(int i=nu;i<=num;i++){
			if(c[i]<=m){
				x[c[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<x[i]<<' ';
	}
	return 0;
}
