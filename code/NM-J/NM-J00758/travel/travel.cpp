#include<bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,c=0,d=0,x,y,i;
	cin>>n>>a>>m>>b;
	for(i=0;i<2;++i) c=c*10+a[i]-'0',d=d*10+b[i]-'0';
	x=a[2]-'A'+1,y=b[2]-'A'+1;//123 ABC 56 DF
	if(a[2]=='D') ++x;
	if(b[2]=='D') ++y;
	if(n!=m) cout<<"0000";
	else
	{
		cout<<"1";
		if(c!=d) cout<<"000";
		else
		{
			cout<<"1";
			if((x<4&&y<4)||(x>4&&y>4))
			{
				cout<<"1";
				if(abs(x-y)>1) cout<<"0";
				else cout<<"1";
			}
			else cout<<"00";
		}
	}
	return 0;
}
