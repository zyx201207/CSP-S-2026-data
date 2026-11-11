#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[200010],s,sk,k,a,t;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		s+=w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		sk=0;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			sk+=t;
		}
		sk/=k;
		s+=sk;
	}
	cout<<s<<"\n";
	while(q--)
	{
		cin>>a>>t;
		cout<<(rand()%s+rand()%s)%s<<"\n";
	}
	int score=0;
	for(int i=1;i<=25;i++) score+=(rand()%2)*4;
	string I;
	if(score<=10) I="Dead";
	else if(score<=30) I="Alive";
	else I="Happy";
	return 0;
}//一点不会 
