#include <bits/stdc++.h>
using namespace std;
int main()
{freopen("r","and.in",stdin);
	freopen("w","and.out",stdout);
int m;
	int f;
	int d;
	int n;
	vector<int> a;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{cin>>d;
		a.push_back(d);
		}
		a.sort(a.begin,a.end);
	for(int i=0;i<n;i++)
	{f=a[i]&&a[i+1]}	
	return 0;}
