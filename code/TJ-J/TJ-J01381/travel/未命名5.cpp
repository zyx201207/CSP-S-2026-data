#include <bits/stdc++.h>
using namespace std;
int n,m,a[200001],b[31],c[31],ans=0;
bool vis[200001]={};
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=3;i++){
		int x=1;
		for(int j=1;j<i;j++) x*=2;
		c[i]=x;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
		while(x){
			int k=lower_bound(c+1,c+n+1,(x&-x))-c;
			b[k]++;
			x-=(x&-x);
		}
 	}
		for(int j=1;j<=30;j++) cout<<b[j]<<" ";
	return 0;
}
