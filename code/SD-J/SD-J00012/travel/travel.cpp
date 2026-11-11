#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b,c,d;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c)
	{
		cout<<1;
	}else 
	{
		cout<<"0000" ;
		return;
	}
	if(b==d)
	{
		cout<<1;
	} else{
		cout<<"000";
		return;
	} 
	if((e<='C'&&f<='C')||(e>'C'&&f>'C'))
	{
		cout<<1;
		if(abs(e-f)==1)
		{
			cout<<1;
		}else cout<<0;
	}else cout<<"00";
	return;
	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
 } 
