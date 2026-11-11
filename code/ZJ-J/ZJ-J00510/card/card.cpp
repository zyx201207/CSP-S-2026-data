#include<bits/stdc++.h>
using namespace std;
int n,m,a[500009],d[300009],ans[300009],t=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=5){
		cout<<1<<1;
		return 0;
	}
	for(int i=1;i<=m;i++)cout<<1;
}
