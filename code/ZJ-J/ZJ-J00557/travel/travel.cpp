#include <bits/stdc++.h>
using namespace std;
#define int long long
int x,xx,y,yy;
char cx,cy;
signed main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>xx>>cx>>y>>yy>>cy;
	if (x!=y) cout<<"0000";
	else
	{
		cout<<"1";
		if (xx!=yy) cout<<"000";
		else
		{
			cout<<"1";
			if (
			(cx=='A'&&cy=='B')||
			(cx=='B'&&cy=='A')||
			(cx=='A'&&cy=='C')||
			(cx=='C'&&cy=='A')||
			(cx=='B'&&cy=='C')||
			(cx=='C'&&cy=='B')||
			(cx=='D'&&cy=='E')||
			(cx=='E'&&cy=='D')
			)
			{
				cout<<"1";
				if ((cx=='A'&&cy=='C')||(cx=='C'&&cy=='A')) cout<<"0";
				else cout<<'1';
			}
			else cout<<"00";
		}
	}
	
	return 0;
}
