#include<bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1==s3) cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	int c=0, z=0;
	char x, y;
	for(int i=0; i<=2; i++)
	{
		if(i==0||i==1)
		{
		    c*=10;
		    z*=10;
		    c+=s2[i]-'0';
		    z+=s4[i]-'0';
	    }
	    else{
	    	x=s2[i];
	    	y=s4[i];
		}
	}
	if(c==z) cout << 1;
	else{
		cout << "000";
		return 0;
	}
	if('A'<=x&&'c'>=x)
	{
		if('A'<=y&&'C'>=y) cout << 1;
		else
		{
			cout << "00";
			return 0;
		}
	}
	else{
		if('A'<=y&&'C'>=y){
			cout << "00";
			return 0;
		}
		else cout << 1;
	}
	if(x-1==y||x+1==y) cout << 1;
	else cout << 0;
	return 0;
}
