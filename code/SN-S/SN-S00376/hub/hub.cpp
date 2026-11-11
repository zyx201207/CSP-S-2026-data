//张海辰 西安铁一中滨河学校高级中学 SN-S00376
#include<bits/stdc++.h>
using namespace std;
int a[20];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	long long n,k;
	int i;
	cin>>c>>t>>n>>k;
	for(int j=1;j<=n;j++)
	cin>>a[i];
	for(int mask=1;mask<(1<<n);mask++)
	{
		for(int m=0;m<(1<<m);m++)
		cout<<a[m]<<" ";
	cout<<"\n";	
	}
	
	return 0;
}
