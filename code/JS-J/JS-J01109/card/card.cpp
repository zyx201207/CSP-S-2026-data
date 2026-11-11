#include<bits/stdc++.h>
#define ll long long 
#define vet vector
using namespace std;
const int N=5e5+10,M=3e5+10;

int a[N];
int n,m;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=m;i++)printf("%d",i);
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
