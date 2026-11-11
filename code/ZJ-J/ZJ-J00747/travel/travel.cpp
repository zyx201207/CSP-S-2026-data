#include <bits/stdc++.h>
#define ll long long
using namespace std;
string ar,br,ax,bx;
map <char,ll> m;
bool check(char a,char b)
{
	if (a > b) swap(a,b);
	if ((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D' && b == 'F')) return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> ar >> br >> ax >> bx;
	m['A']=m['B']=m['C']=0;
	m['D']=m['F']=1;
	if (ar == ax)
	{
		if (br[0] == bx[0] && br[1] == bx[1]) 
		{
			if (m[br[2]] == m[bx[2]])
			{
				if (check(br[2],bx[2])) cout << "1111";
				else cout << "1110";
			}
			else cout << "1100";
		}
		else cout << "1000";
	}
	else cout << "0000";	
	return 0;
}
// No boom please...
// Why does the computer don't have Chinese ShuRuFa?
// I only can use my very bad English to write.
// CCF I love you please give me 1= !
// luogu: @people123
