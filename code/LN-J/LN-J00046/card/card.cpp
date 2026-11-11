#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],x,b[300005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			b[a[j]]++;
			j=c[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}
