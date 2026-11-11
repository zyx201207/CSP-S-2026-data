#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600000],b[600000],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=cnt;k++){
				if(b[k]==a[j]){
					cnt=k-1;
					break;
				}
			}
			b[++cnt]=a[j];
		}
		for(int i=1;i<=cnt;i++){
			c[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
