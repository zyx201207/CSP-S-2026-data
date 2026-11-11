#include<iostream>
using namespace std;
int main()
{
	freopen( "travel.in" , "r" , stdin );
	freopen( "travel.out" , "w" , stdin ) ;
	string lttlR , lttlR_st , lttlX , lttlX_st ;
	cin >> lttlR >> lttlR_st >> lttlX >> lttlX_st;
	if( lttlR == lttlX )
	{
		cout << "1" ;
		if( lttlR_st[ 0 ] == lttlX_st[ 0 ] && lttlR_st[ 1 ] == lttlX_st[ 1 ] )
		{
			cout << "1" ;
			int rst = lttlR_st[ 2 ] - 'A' + 1 , xst = lttlX_st[ 2 ] - 'A' + 1 ;
			if( ( rst <= 3 && xst <= 3 ) || ( rst > 3 && xst > 3 ) )
			{
				cout << "1"; 
				if( rst - xst == 1 || xst - rst == 1 )
				{
					cout << "1" ;
				}
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
			cout << "000" ;
		}
	}
	else
	{
		cout <<"0000";
	}
	return 0;
}
