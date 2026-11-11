#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct W
{
	 int s;
     int cha ;
 };
bool cmp(W x,W y)
{
	return x.cha < y.cha;
}
W a[500010];
int b[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long   n , m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
    	cin >> a[i].s;
    }
    for(int i=1;i<n;i++)
    {
    	for(int j=0;j<i;j++)
    	{
   		    
			a[i].cha += (a[i].s-a[j].s);    		 
		} 
	}
	int cnt = 0;
	sort(a,a+n-1,cmp);
	for(int i = 0 ; i < n ; i++)
	{ 
		if(a[i].cha <= m) cnt++;
		else break; 
	}
	cout<<cnt;
	return 0;
}

