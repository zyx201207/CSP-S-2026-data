#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) c[j]=0;
		map<int,int>ma;
		for(int j=i;j<=n;j++){
			c[j]=a[j];
			if(ma[c[j]]!=0) {
				for(int _=ma[c[j]];_<j;_++) {
					ma[c[_]]=0;
					c[_]=0;
				}
			}
			ma[c[j]]=j;
		}
		for(int j=i;j<=n;j++){
		//	if(c[j]==2) cout<<j<<'\n';
			b[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
} 
