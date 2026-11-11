#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,i;
	cin>>a;
	int b[a];
	string c[a],d,f;
	for(i=0;i<a;i++)
	{
		cin>>b[i]>>c[i];
		}
	for(i=0;i<a;i++)
	{
		for(int z=0;z<b[i];z++)
		{
			d=d+c[i];
			}
		}
	f=d;
	sort(d.begin(),d.end(),greater<char>());
	sort(f.begin(),f.end());
	if(d==f) cout<<0;

	else
	{
		cout<<1;
		}
	return 0;
	}
	
		
