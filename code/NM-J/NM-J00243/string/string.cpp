#include<bits/stdc++.h>
using namespace std;

int n;
string b = "";
string a = "";

int main()
{
	freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
	cin >> n;
	int cnt = 0;
	while(n--)
	{
		int x;
		string c;
		cin >> x >> c;
		for(int i = 1 ; i <= x ; i++)
		{
			a += c;
			b += c;
		}
		reverse(a.begin() , a.end());
		if(a != b)
		{
			for(int i = 0 ; i < a.size() ; i++)
			{
				if(a[i] != b[i])cnt++;
			} 
		}
	}
	cout << cnt;
	return 0;
}
