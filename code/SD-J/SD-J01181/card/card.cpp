#include<bits/stdc++.h>
using namespace std;
const int N=5E5+10;
#define ll long long
int n,m;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=m;i++)
		printf("%d ",i);
	return 0;
}
