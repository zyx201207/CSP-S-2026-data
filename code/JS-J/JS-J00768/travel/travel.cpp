#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=1e5+1;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s2,s4;
	ll s1,s3;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
	{
		cout<<1;
		if(s2[0]==s4[0] && s2[1]==s4[1])
		{
			cout<<1;
			if('A'<=s2[2] && s2[2]<='C' && 'A'<=s4[2] && s4[2]<='C')
			{
				cout<<1;
				if(abs(s2[2]-s4[2])<=1) cout<<1<<endl;
				else cout<<0<<endl;
			}
			else if((s2[2]=='D' && s4[2]=='F') || (s2[2]=='F' && s4[2]=='D'))
				cout<<"11"<<endl;
			else cout<<"00"<<endl;
			
		}
		else cout<<"000"<<endl;
	}
	else cout<<"0000"<<endl;
	return 0;
}
