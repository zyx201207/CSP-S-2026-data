#include<bits/stdc++.h>
using namespace std;
int a[200010],b[300010],n,m,c[200010],k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		k=0;
		for(int i=t;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(a[i]==c[j]){
					k=j-1;
					break;
				}
			}
			c[++k]=a[i];
		}
		for(int i=1;i<=k;i++){
			b[c[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
