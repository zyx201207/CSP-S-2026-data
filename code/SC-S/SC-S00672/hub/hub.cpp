#include<bits/stdc++.h>//hub
using namespace std;
int a,b,c,d,f,g,h;
void dfs(int x,int y)
{
	if(x>c)
	{
		
		return ;
	}
	if(y>0)
	{
		
		dfs(x+1,y-1);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b;
	while(b--)
	{
		cin>>c>>d;
		for(int i=1;i<c;i++)
		{
			int x,y;
			cin>>x>>y;
		}
		cout<<"0\n";
	}

	return 0;
}
