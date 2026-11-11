#include<bits/stdc++.h>
using namespace std;
int a[110000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int i,j,m,n,q,s=0,maxa=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>q;
		a[q]=q;
		s=q;
		maxa=max(maxa,s);
	}
		if(m==1)
		{
			cout<<0;
		}
	
	
		
	return 0;
}
