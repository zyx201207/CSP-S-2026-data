#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	int k1,k2;
	string n1,n2;
	cin >> k1>>n1>>k2>>n2;
	if(k1 == k2)
	{
		cout <<"1";
		if(n1[1]==n2[1]&&n1[2] == n2[2])
		{
			cout <<"1";
			
			if(((n1[3] == 'A'||n1[3] == 'B'||n1[3] == 'C')&&(n2[3] == 'A'||n2[3] == 'B'||n2[3] == 'C'))||((n1[3] == 'D'||n1[3] == 'E')&&(n2[3] == 'D'||n2[3]== 'E' )){
		    	cout << "1";
		    	if(n1[3]+1==n2[3]||n1[3]-1==n2[3])
		    	    cout <<"1";
		    	else
		    	{
		    		cout << "0";
				}
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout <<"000";
		}
	} 
	else
	{
		cout <<"0000";
	}
	
	return 0;
}
