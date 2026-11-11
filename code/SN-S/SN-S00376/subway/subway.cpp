//张海辰 西安铁一中滨河学校高级中学 SN-S00376
#include<bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,m,d,q;
	int r,n,i;
	cin>>c>>n>>m>>d>>q;
	for(int z=1;z<=m;z++)
		cin>>a[z];
	for(int z=1;z<=n;z++)
		cin>>b[z];
	string s;
	cin>>s;
	sort(a+1,a+m+1);
	for(int d=1;d<=n;d++)
	{
		int l=a[1],r=a[d];
		if(i<a[d]/2)
		r=a[d]/2;
		if(i>a[d]/2)
		l=a[d]/2;
	}
	cout<<c+n+m+d;
	return 0;
}
