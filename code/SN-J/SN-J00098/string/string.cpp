#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n; i++)
	{
		int v;
		cin >> v;
		string q;
		cin >> q;
		for(int j = 0;j < v; j++)
		{
			s+=q;
		}
		
	}
	int cnt = 0;
	for(int i = 0; i <= s.size()/2-1; i++)
	{
		for(int j = s.size()-1-i; j >= s.size()/2+s.size()%2; j--)
		{
			if(s[i]!= s[j])
			{
				cnt++;
				break;
			}
			
		}
	}
	cout << cnt;
	return 0;

 } 
