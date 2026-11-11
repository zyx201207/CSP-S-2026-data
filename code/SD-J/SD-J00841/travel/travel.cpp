#include<iostream> 
#include<string> 
using namespace std;

int main()
{
	//system("fc /w travel.out travel.out");
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s,ss,sa,as;
	cin>>s>>ss>>sa>>as;
	if(s==sa)
	{
		cout<<1;
		string a=ss.substr(0,2),b=as.substr(0,2);
		if(a==b)
		{
			cout<<1;
			a=ss.substr(2,1);
			b=as.substr(2,1);
			if(a<="C"&&b<="C"||a>="D"&&b>="D")
			{
				cout<<1;
				if(a<="C"&&b<="C"&&(a=="B"||b=="B")||a>="D"&&b>="D")
				{
					cout<<1;
				}
				else
				{
					cout<<0<<"\n";
				}
			}
			else
			{
				cout<<"00"<<"\n";
			}
		}
		else
		{
			cout<<"000"<<"\n";
		}
	}
	else
	{
		cout<<"0000"<<"\n";
	}
	return 0;
}
