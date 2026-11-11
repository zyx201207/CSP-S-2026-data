#include<bits/stdc++.h>
#define ll long long
#define db double
const int N=1e6+10,inf=0x3f3f3f3f;
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int cnt1=(c1[0]-'0')*10+(c1[1]-'0');
	int cnt2=(c2[0]-'0')*10+(c2[1]-'0');
	if(cnt1==cnt2)
	{
		int sum1=(s1[0]-'0')*10+(s1[1]-'0');
		int sum2=(s2[0]-'0')*10+(s2[1]-'0');
		if(sum1==sum2)
		{
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))
			{
				if(((s1[2]+1)==s2[2])||((s1[2]-1)==s2[2]))
					cout<<"1111";
				else
					cout<<"1110";
			}
			else
				cout<<"1100";
		}
		else
			cout<<"1000";
	}
	else
		cout<<"0000";
	return 0;
}
