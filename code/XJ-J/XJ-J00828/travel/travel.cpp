#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travei.out","w",stdout);
	string rc,rs,xc,xs;
	string cnt = "0000";
	cin >> rc >> rs >> xc >> xs;
	if(rc == xc) cnt[0] = '1';
	else cnt[0] = '0';
	if(cnt[0] == '1' && rs[0] == xs[0] && rs[1] == xs[1]) cnt[1] = '1';
	else cnt[1] = '0';
	if((rs[2] == 'C' && xs[2] == 'D') || (rs[2] == 'D' && xs[2] == 'C')) cnt[2] = '0';
	else if(cnt[1] == '1') cnt[2] = '1';  
	if((rs[2] + 1 == xs[2] || rs[2] - 1 == xs[2]) && cnt[2] == '1') cnt[3] = '1';
	else cnt[3] = '0';
	cout << cnt;
	return 0;
}