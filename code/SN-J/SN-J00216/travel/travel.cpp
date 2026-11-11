#include<bits/stdc++.h>
using namespace std;
int as[5] = {};
int sa[5] = {};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string a,s;
	cin >> n >> a >> m >> s;
	for(int i = 0;i < 3;i++)
	{
		as[i] = a[i] - '0';
		sa[i] = s[i] - '0';
	}
	if(n == m)
	{
		cout << "1";
		if(as[0] == sa[0] && as[1] == sa[1])
		{
			cout << "1";
			if((as[2] <= 51 && sa[2] <= 51) || (as[2] >= 52 && sa[2] >= 52))
			{
				cout << "1";
				n = as[2] - sa[2];
				if(n == 1 || n == -1)
				{
					cout << "1";
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	
	return 0;
} 
