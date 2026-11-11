#include<bits/stdc++.h>
using namespace std;
int c,c2,h,h2;
char r,r2,tmp1,tmp2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>tmp1>>tmp2>>r;
	h = (tmp1 - '0') * 10 + tmp2 - '0';
	cin>>c2>>tmp1>>tmp2>>r2;
	h2 = (tmp1 - '0') * 10 + tmp2 - '0';
	if (r == 'F') r --;
	if (r2 == 'F') r2 --;
	bool fl = c == c2;
	cout<<fl;
	fl &= h == h2;
	cout<<fl;
	fl &= (r >= 'D') == (r2 >= 'D');
	cout<<fl;
	fl &= abs(r - r2) <= 1;
	cout<<fl;
	return 0;
}