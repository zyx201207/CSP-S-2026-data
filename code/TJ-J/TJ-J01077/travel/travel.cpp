#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mk make_pair
bool ST;
bool ED;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c)cout<<"0000";
	else
	{
		cout<<1;
		if(b[0]!=d[0]||b[1]!=d[1])cout<<"000";
		else
		{
			cout<<1;
			char x=b[2],y=d[2];
			if(x>y)swap(x,y);
			if((x<='C'&&y<='C')||(x>='D'&&y>='E'))
			{
				cout<<1;
				if(y-x==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
	}
//	cerr<<"\nTime used: "<<1.0*clock()/CLOCKS_PER_SEC*1000<<"ms\n";
//	cerr<<"Memory used: "<<abs(&ST-&ED)/1024.0/1024.0<<"mb\n";
	return 0;
}
