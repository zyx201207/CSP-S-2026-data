#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	if (n == 1)
	{
		cout << "0";
	}
	if (n == 2)
	{
		string s;
	    long long k = 0, sum = 0;
	    for (int i = 1; i <= 2; i++)
	    {
		    long long h;
		    cin >> h;
		    string a;
		    cin >> a;
		    k += h;
		    for (long long j = 1; j <= h; j++)
		    {
		    	s += a;
		    }
	    } 
		//cout << s << " " << k << " ";
		for (int i = 0; i <= k/2; i++)
		{
			if (s[i] != s[k-1-i])
			{
				sum++;
			}
		}
		cout << sum;
	}
	if (n > 2)
	{
		string s, d;
	    long long zc = 0; //zong3 chang2
	    for(int i = 1; i <= n; i++)
	    {
		    long long b;
		    string s2;
		    cin >> b >> s2;
		    zc += b;
		    for (int j = 1; j <= b; j++)
		    {
		    	s += s2;
		    }
	    }
	    for(int i = zc-1; i >= 0 ; i--)
	    {
	    	d += s[i];
	    }
	    //cout << s << endl << d;
	    long long sum = 0;
	    long long lf[zc+5]; //lun guo de zi fu
	    for (int i = 0; i < zc; i++)
	    {
	    	lf[i] = 0;
	    }
	    for (long long i = 0; i < zc; i++)
	    {
	        if (s[i] != d[i])
	    	{
	    		for (long long j = 1; j < zc; j++)
	    		{
	    			long long h = 1;
	    			if ((s[j] == s[i] and d[j] == d[i]) or (s[j] == d[i] and d[j] == s[i]))
	    			{
	    				if (lf[j] == 0)
	    				{
	    					h++;
	    					lf[j]++;
	    				}
	    			}
	    			sum += h/2;
	    		}
	    	}
	    }
	    cout << sum-1;
    }
	return 0;
}