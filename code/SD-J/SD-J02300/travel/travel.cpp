#include<bits/stdc++.h>
using namespace std;
#define int long long
string ca,sa,cb,sb;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	//cout<<" "<<1<<" ";
	int pa=0,pb=0;
	for(int i=0;i<sa.size();i++)
	{
		if(sa[i]>='0'&&sa[i]<='9')
		{
			//cout<<pa<<" ";
			pa=pa*10+sa[i]-'0';
		}
	}
	for(int i=0;i<sb.size();i++)
	{
		if(sb[i]>='0'&&sb[i]<='9')
		{
			//cout<<pb<<" ";
			pb=pb*10+sb[i]-'0';
		}
	}
	if(pa==pb)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	//cout<<" "<<2<<" ";
	//cout<<" "<<sa[sa.size()-1]-'A'+1<<" "<<sb[sb.size()-1]-'A'+1<<" ";
	if(sa[sa.size()-1]-'A'+1<=3&&sb[sb.size()-1]-'A'+1<=3||sa[sa.size()-1]-'A'+1>=4&&sb[sb.size()-1]-'A'+1>=4)
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	//cout<<" "<<3<<" ";
	//cout<<" "<<abs(sa[sa.size()-1]-sb[sb.size()-1])<<" ";
	if(abs(sa[sa.size()-1]-sb[sb.size()-1])==1)
	{
		if(sa[sa.size()-1]=='C'&&sb[sb.size()-1]=='D'||sa[sa.size()-1]=='D'&&sb[sb.size()-1]=='C')
		{
			cout<<0;
			return 0;
		}
		cout<<1;
	}
	else
	{
		cout<<0;
		return 0;
	}
	//cout<<" "<<4<<" ";
	return 0; 
}
