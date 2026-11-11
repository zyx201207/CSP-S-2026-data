#include <bits/stdc++.h>
using namespace std;

bool check(int x,int y)
{
	if(x != y)
	{
		return false;
	}
	return true;
}
int n,m;
int a[1000010],b[1000010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>> n >> m;
    for(int i = 1; i<= n;i++)
    {
    	cin>> a[i];
    	b[i-1] = a[i]- a[i-1];
	}
    sort(a+1,a+n+1);
    int l =1,r = n,mid = 0;
    
    
    
    cout << m/n;
	return 0;
}
