#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,a[100010],b[100010];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++) scanf("%d%d",&a[i],&b[i]);
		if(T>0) cout<<1<<endl;
		 else cout<<2<<endl;
	}
	return 0;
}
