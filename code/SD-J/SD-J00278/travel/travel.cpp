#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1,s2,a1,a2;
	cin>>s1>>s2>>a1>>a2;//车厢号，座位，车厢号，座位 
	if(s1==a1)//同车厢 
	{
		cout<<1;
		string n=s2.substr(0,2);
		string m=a2.substr(0,2);
	//	cout<<n<<" "<<m<<endl;
		if(n==m)//同排 
		{
			cout<<1;
			if((s2[2]>'C'&&a2[2]>'C')||(s2[2]<='C'&&a2[2]<='C'))//同一侧 
			{
				cout<<1;
				if((s2[2]+1==a2[2])||(s2[2]-1==a2[2]))//挨着 
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
