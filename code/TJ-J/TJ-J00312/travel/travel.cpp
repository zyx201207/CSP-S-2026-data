#include <iostream> 
#include <cmath>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char arr[101],add[101];
	int a,b;
	bool pai = false;
	bool che = false;
	bool ce = false;
	cin >> a >> arr >> b >> add;
	if(a == b)
	{
		che = true;
		cout <<"1";
	}
	else
	{
		cout <<"0";
	}
	int aa = int(arr[0] - '0') * 10 + int(arr[1] - '0');
	int bb = int(add[0] - '0') * 10 + int(add[1] - '0');
	if(aa == bb and che == true)
	{
		cout << "1";
		pai = true;
	}
	else
	{
		cout <<"0";
	}
	if(che == true and pai == true and ((arr[2] >= 'A' and arr[2] <= 'C' and add[2] >= 'A' and add[2] <= 'C') or (arr[2] == 'D' and add[2] == 'F') or (arr[2] == 'F' and add[2] == 'D')))
	{
		cout <<"1";
		ce = true;
	}
	else
	{
		cout << "0";
	}
	if(che == true and pai == true and ce == true)
	{
		if(arr[2] == 'F' or arr[2] == 'D')
		{
			if(add[2] == 'D' or add[2] == 'F')
			{
				cout <<"1";
			}
			else
			{
				cout <<"0";
			}
		}
		else if(abs(arr[2] - add[2]) == 1)
		{
			cout <<"1";
		}
		else
		{
			cout << "0";
		}
	}
	else
	{
		cout <<"0";
	}
	
	
	
	
	
	return 0;
}
