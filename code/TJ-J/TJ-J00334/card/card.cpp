#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[300005],c[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f=-1;
		for(int j=1;j<=n;j++){
			if(a[i]==a[j]){
				c[i]=a[i];
			}
		}
		for(int j=1;j<=n;j++){
			b[c[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
