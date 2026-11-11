#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	int n,m;
	string a,s;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> m >> a;
		for(int j = 0;j < m;j++)
		{
			s += a;
		}
	}
	for(int i = 0;i < s.size();i++)
	{
		a[i] = s[s.size() + 1 - i]; 
	}
	cout << a;
	
	return 0;
} 
