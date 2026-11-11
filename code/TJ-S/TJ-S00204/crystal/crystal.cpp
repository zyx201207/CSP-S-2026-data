#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500001],b[500000];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,l=-1,k,j;
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		cin>>a[x];
	}
	sort(a+1,a+n+1);
	for(int x=2;x<=n;x++){
		b[x]=a[x]-a[x-1];
	}
	for(int x=1;x<=n;x++){
		k=m;
		j=1;
		for(int y=x+1;y<=n;y++){
			if(k<b[y]){
				break;
			}
			k-=b[y];
			j++;
		}
		l=max(l,j);
	}
	cout<<l;
	return 0;
}
