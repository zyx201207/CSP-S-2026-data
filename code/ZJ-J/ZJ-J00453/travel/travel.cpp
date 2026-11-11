#include <bits/stdc++.h>
using namespace std;
string cr,cx,sr,sx;
int flag=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if (cr[0]!=cx[0]) flag=0;
	if (cr[1]!=cx[1]) flag=0;
	cout<<flag;
	if (sr[0]!=sx[0]) flag=0;
	if (sr[1]!=sx[1]) flag=0;
	cout<<flag;
	if (sr[2]>'C' and sx[2]<'D') flag=0;
	if (sx[2]>'C' and sr[2]<'D') flag=0;
	cout<<flag;
	if (sr[2]!=sx[2]+1 and sr[2]!=sx[2]-1) flag=0;
	cout<<flag;
	return 0;
}