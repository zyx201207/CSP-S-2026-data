#include<bits/stdc++.h> 
#include<cstdio>
int c,n,m,d,q,r,k,w[10005][10005],a[10005][10005];
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=i;j++) 
	cin>>w[i][j];
	}
	for(int i=3;i<=32;i++){
	q++;
	r=q-15;
}
	cout<<q<<endl<<r;
	return 0;
}
