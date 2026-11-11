#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[300010];
int c[300010];
int d[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int l=i;
		memset(c,0,sizeof c);
		for(int j=i;j<=n;j++){
			if(c[a[j]]>=l){
				l=j;
				c[a[j]]=j;
			}else c[a[j]]=j;
		}
		for(int j=l;j<=n;j++)d[a[j]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}