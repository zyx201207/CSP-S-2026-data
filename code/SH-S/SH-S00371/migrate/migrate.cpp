#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int c,T,n,d,pos[2000005];
void SpjA()
{
	int gc=pos[2]-pos[1];
	if(d==0||d==gc)
		cout<<0<<endl;
	else
		cout<<max(n-2*d/gc+1,0LL)<<endl;
	return ;
}
void SpjB()
{
	cout<<0<<endl;
	return ;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		memset(pos,0,sizeof(pos));
		for(int i=1;i<=n;i++)
			cin>>pos[i];
		if(c==11||c==12)
		{
			SpjA();
			continue;
		}
		if(c==13||c==14)
		{
			SpjB();
			continue;
		}
//		
	}
	return 0;
}

