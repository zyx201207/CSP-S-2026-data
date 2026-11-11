#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() 
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);	
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	string ca,sa,cb,sb;
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb)
	{
		cout<<"1";
		if(sa[0]==sb[0]&&sa[1]==sb[1]) 
		{
			cout<<"1";
			if(sa[2]=='A'||sa[2]=='B'||sa[2]=='C')
			{
				if(sb[2]=='A'||sb[2]=='B'||sb[2]=='C')
				{
					if(sa[2]=='B'||sb[2]=='B') cout<<"11";
					else cout<<"10"; 					
				}
				else cout<<"00";
			}
			else
			{
				if(sb[2]=='D'||sb[2]=='F') cout<<"11"; 
				else cout<<"00";				
			}
		}
		else cout<<"000";
	} 
	else cout<<"0000";
	return 0;
}
//666,纯if+思维题,难度:入门
//预估：100