#include <bits/stdc++.h>

using namespace std;

string a[100000];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	int cnt=0,boundary=0;
	for(int i=0;i<n;i++)
	{
		int num;
		string zf;
		cin >> num >> zf;
		cnt+=num;
		for(int j=boundary;j<cnt;j++)
		{
			a[j]=zf;
			boundary++;
		}
	}

    boundary=0;
	int l=0;
	int r=cnt-1;
	
	while(l<r)
	{
		if(a[l]!=a[r])
		{
			boundary++;
		}
		l++;
		r--;
	}
	
	cout << boundary;
	
	return 0;
}
