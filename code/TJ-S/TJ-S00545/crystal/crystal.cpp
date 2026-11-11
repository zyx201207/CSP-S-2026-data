#include<iostream>
using namespace std;

int main(){
	int n;
	int m;
	cin >> n >> m;
	int x = 0;//大水晶合成的数量 
	int a;
	int b;
	int c;
	int d;
	int e;
	cin >> a >> b >> c >> d >> e;
	
	if(a > b > c >d > e)
	{
		if(m <  c -  b +  c -  a)
		{
			x ==2;
		}
		else if(m <  c -  b)
		{
			x == 1;
		}
		else
		{
			x == 3;
		}
	}
	cout << x << endl;
		
	

	return 0;
}

