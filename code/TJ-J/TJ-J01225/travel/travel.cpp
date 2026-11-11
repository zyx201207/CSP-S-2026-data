#include <bits/stdc++.h>
using namespace std;
bool f = false;
int main()
{
	freopen( "travel.in" , "r" , stdin );
	freopen( "travel.out" , "w" , stdout );
	string cr , sr , cx , sx;
	cin >> cr >> sr >> cx >> sx;
	if ( cr == cx ) cout << 1; //在同一车厢 
	else if ( cr != cx ) cout << 0;
	if ( sr[0] == sx[0] && sr[1] == sx[1] && cr == cx )
	{
		cout << 1; //在同一排 
		f = true;
    }
	else  cout << 0;
	if ( sr[2] >= 'D' && sr[2] <= 'F' && sx[2] >= 'D' && sx[2] <= 'F' && f == true && cr == cx || sr[2] >= 'A' && sr[2] <= 'C' && sx[2] >= 'A' && sx[2] <= 'C' && f == true && cr == cx ) cout << 1; //在同一排，同一侧 
	else cout << 0;
	if ( sr[2] == 'D' && sx[2] == 'F' && f == true || sr[2] == 'F' && sx[2] == 'D' && f == true || sr[2] == 'A' && sx[2] == 'B' && f == true || sr[2] == 'B' && sx[2] == 'A' && f == true || sr[2] == 'B' && sx[2] == 'C' && f == true || sr[2] == 'C' && sx[2] == 'B' && f == true  ) cout << 1;
	else cout << 0;
}
