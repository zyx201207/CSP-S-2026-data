#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,x;
    cin >> n;
    string a[n][2];
    for (int i = 0;i < n;i++)
    {
        for(int j = 0;j < 2;j++)
		{
		    cin >> a[i][j];
	    }
	    cout << endl;
    }
    for (int i = 0;i < n;i++)
    {
        if(a[0][1] == a[n-1][1]) cout << "0";
    }
    //return 0;
}

