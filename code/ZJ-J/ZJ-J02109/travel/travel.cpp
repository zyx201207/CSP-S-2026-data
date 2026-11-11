#include<bits/stdc++.h>
using namespace std;
int ans[10];
int a,c;
string b,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c&&a!=1&&a!=16&&c!=1&&c!=16)
	{
		ans[1]=1;
		bool f=1;
		for(int i=0;i<=1;i++)
			if(b[i]!=d[i]){
				f=0;
			}
		if(f==1)
		{
			ans[2]=1;
			if(b[2]<='C'&&d[2]<='C' || b[2]>='D'&&d[2]>='D'){
				ans[3]=1;
				if(b[2]==d[2]+1 || b[2]==d[2]-1)
					ans[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++)
		cout<<ans[i];
	return 0;
}