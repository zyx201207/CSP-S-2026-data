#include <bits/stdc++.h>
using namespace std;
//struct
long long a[100005];
string c[100005];
long long sum = 0,out = 0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		//cout << i << "--" << a[i] << "--" << c[i] << "--" << sum << endl;
		sum += a[i];
		//cout << sum << ";;" << endl;
	}
	
	long long mid = sum / 2;
	long long l = 1,r = n;
	
	//int BW,W,Q,B,S;
	//cout << mid << ";;" << endl;
	for (long long i = 0;i < mid;i++)
	{
		string x,y;/*
		int val = 1;
		if ((a[l] > 100000 && a[r] > 100000) && i + 100000 < mid)
		{
			x = c[l];
			y = c[r];
			a[l] -= 100000;
			a[r] -= 100000;
			val = 100000;
		}
		else if ((a[l] > 10000 && a[r] > 10000) && i + 10000 < mid)
		{
			x = c[l];
			y = c[r];
			a[l] -= 10000;
			a[r] -= 10000;
			val = 10000;
		}
		else if ((a[l] > 1000 && a[r] > 1000) && i + 1000 < mid)
		{
			x = c[l];
			y = c[r];
			a[l] -= 1000;
			a[r] -= 1000;
			val = 1000;
		}
		else if ((a[l] > 100 && a[r] > 100) && i + 100 < mid)
		{
			x = c[l];
			y = c[r];
			a[l] -= 100;
			a[r] -= 100;
			val = 100;
		}
		else if ((a[l] > 10 && a[r] > 10) && i + 10 < mid)
		{
			x = c[l];
			y = c[r];
			a[l] -= 10;
			a[r] -= 10;
			val = 10;
		}
		else
		{*/
	    	if (a[l] >= 1)
	    	{
	     		x = c[l];
	    		a[l] --;
	    	}
	    	else
	    	{
	    		l += 1;
	    		x = c[l];
	    		a[l] --;
	    	}
		    
	    	if (a[r] >= 1)
	        	{
		    	y = c[r];
		    	a[r] --;
		    }   
	    	else
	    	{
		    	r -= 1;
		    	y = c[r];
		    	a[r] --;
	    	}
	    //}
		//cout << i << "--" << x << "--" << y << endl;
		if (x != y)
		{
			out++;
			//out += val;
			//val --;
            //i += val;
		}
	}
	//cout << BW << "--" << W << "--" << Q << "--" << B << "--" << S << endl;
	cout << out;
	
	return 0;
}
