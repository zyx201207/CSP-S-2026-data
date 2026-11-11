 #include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin >> n;
	int m;
	cin >> m;
	int minn=0;
	int f;
	for(int i=0;i<n;i++)
	{
		cin >> f;
		if(f>minn)
		{
			minn=f;
		}
	}
	cout << f;
	return 0;
}
