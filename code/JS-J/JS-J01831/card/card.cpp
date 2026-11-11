#include <bits/stdc++.h>
using namespace std;
int n,m,a[10001],b[10001],bj,c[10001],s;
int main(){
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	    s=0;
		for(int j=i;j<=n;j++){
			for(int x=1;x<=s;x++){
				if(b[x]==a[j]){
					bj=x;
				}
			}
			for(int x=1;x<=s-bj;x++){
				b[x]=b[x+bj];
			}
			for(int x=s-bj+1;x<=s;x++){
				b[x]=0;
			}
			s=s-bj;
			s++;
			b[s]=a[j];
		}
		for(int j=1;j<=s;j++){
			c[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
