#include"bits/stdc++.h"
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	bool vv=true;
	string fw="";
	string mw="";
	string w="";
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		string sa;
		cin>>a;
		cin>>sa;
		for(int j=1;j<=a;j++)
		{
			w+=sa;
		}

	}
	for(int i=w.size()-1;i>=0;i--)
	{
		fw[i]=w[i];
	}
	for(int i=w.size()-1;i>=0;i--)
	{
		for(int j=0;j<=w.size();j++)
		{
			if(fw[i]!=w[j])
			{
				vv=false;
				break;
			}
		}
	}
	if(vv)
	{
		cout<<cnt;
		return 0;
	}
	/*
	while(vv!=true)
	{
		for(int i=w.size();i>=0;i--)
		{
			for(int j=w.size();j>=0;j--)
			{
				if(w[j]!=fw[i])
				{
					w[j]=fw[i];
					vv=false;
					break;
				}
			}

		}
		cnt++;

	}
	*/


	cout<<cnt;
    return 0;
}

/*
3
2 a
2 b
1 c
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

