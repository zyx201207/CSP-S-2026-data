/*
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
*/
//#include<bits\stdc++.h>
#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a,b,aa,bb;
int main()
{
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)
	{
		cout<<"0000";
	}
	else
	{
		cout<<1;
		a=10*(s2[0]-'0')+s2[1]-'0';
		b=10*(s4[0]-'0')+s4[1]-'0';
		aa=s2[2]-('A'-1);
		bb=s4[2]-('A'-1);
		if(a==b)
		{
			cout<<1;
			if(aa<=3&&bb<=3)
			{
				cout<<1;
				if(abs(aa-bb)==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else if(aa>3&&bb>3)
			{
				cout<<1;
				if(abs(aa-bb)==1)
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
	return 0;
}
//start: 8:31
//end: 8:46
/*
wo xiang jin mi huo xing wei da shang
luogu uid=1861592
*/