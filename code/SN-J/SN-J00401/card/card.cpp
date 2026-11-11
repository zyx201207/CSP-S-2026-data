#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
    long long n,m,k[100005];
    for(int i =1,i <= n;i++)
    {
    	cin >> k[i];
	}
    sort(k,k+n+1)
    for(int i =1,i <= m;i++)
    {
    	cout <<k[i];
	}
	return 0;
}
