#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],b[300005],c[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	b[a[n]]=n;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;i++){
			for(int k=i;k<=j;k++){
				if(a[k]==a[j]){
					b[j]==j;
				} 
			}
		}
		for(int j=1;j<=n;j++){
			c[i]=a[i];
		}
	}
	cout<<m;
	for(int i=2;i<=n;i++){
		cout<<b[i];
	}
	return 0; 
}
