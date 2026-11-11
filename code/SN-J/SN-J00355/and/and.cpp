#include<bits/stdc++.h>
using namespace std;
int andd(string a,string b)
{
	string aa,bb;
	vector<int> t;
	while(a)
	{
		t.push_back(a%2);
		a=a/2;
	}
	reverse(t.begin(),t.end());
	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	return 0;
 } 
