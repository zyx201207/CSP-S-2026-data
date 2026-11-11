#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],c[1000005];
int main()
{
	int L;
	cin >> L;
	for(int i=1;i<=L;i++)
	{
		cin >> a[i] >> c[i];
		s += a[i]*c[i];
	}
	string a = s;
	sort(s.begin(),s.end());
	reverse(a.begin(),a.end());
	if(a == s)
	{
		cout << 0;
	}
	return 0;
}