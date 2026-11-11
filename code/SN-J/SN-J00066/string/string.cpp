#include <bits/stdc++.h> 

using namespace std;

int n;
int a[200005];
long long s[200005];
string c[200005];
long long ans = 0;

int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	cin >> n;
	long long l = 0;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i] >> c[i];
		s[i] = s[i - 1] + a[i];
		l += a[i];
	}
	long long L = 1, R = n;
	if (l % 2 == 1) 
	{
    	for (int i = 1; i <= n / 2 + 1; i++)
		{
			if (l + 1 - i < s[R])
			    while(l+1-i >= s[R])
		    	    R--;
			if (c[i] != c[R])
		    	if (a[i] > a[R])
		    	    ans += a[R];
		    	else
		    		ans += a[i];
		}
	}else
    {
    	for (int i = 1; i <= n / 2; i++)
		{
			if (l + 1 - i < s[R])
			    while(l+1-i >= s[R])
		    	    R--;
			if (c[i] != c[R])
			{
			    if (a[i] > a[R])
			        ans += a[R];
			    else
			        ans += a[i];
			}
		}	
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
