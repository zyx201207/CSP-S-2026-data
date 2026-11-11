#include<bits/stdc++.h>
using namespace std;
int n,a,cnt = 0,sum,num;
char c;
string s; 
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
    	cin >> a >> c;
    	sum += a;
    	for(int j = 1;j <= a;j++)
    	{
    		s += c;
		}
	}
	int u = s.size();
	for(int i = 0;i < sum/2;i++)
	{
		if(s[i] != s[sum-i-1])
		{
			cnt++;
		}
	}
	cout << cnt;
    return 0;
}
