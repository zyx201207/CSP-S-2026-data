#include<bits/stdc++.h> 
#define int long long
using namespace std;
string c1,c2;
int a[10],s1,s2,s3,s4;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s1 >> s2 >> s3 >>s4;
	if(s1 == s3 && (s1!="01" || s1 != "16") && (s3!="01" || s3 != "16"))
	{
		a[1] = 1;
		if(s2 == s4)
		{
			a[2] = 1;
	    	if((s2 >= 64 && s2 <= 67) && (s4 >= 64 && s4 <= 67))
	    	{
	       		a[3] = 1;
	        	if(s2 == 66 && s2 == 67)
	        	{
	        		a[4] = 0;
	        	}
	        	else if (s2 - s4 == 1 || s2 - s4 == 1)
	        	{
	        		a[4] = 1;
	        	}
	    }
	    else
	    {
	    	a[3] = 0;
	    	a[4] = 0;
		}
    }
    else
    {
    	a[2] = 0;
    	a[3] = 0;
    	a[4] = 0;
	}
	}
	for(int i = 1;i <= 4;i++)
	{
		cout << a[i];
	}
	return 0;
}
