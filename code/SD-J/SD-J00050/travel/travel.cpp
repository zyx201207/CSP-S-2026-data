#include<bits/stdc++.h> 
//#define int long long
#define endl "\n"
using namespace std;
string c1,s1,c2,s2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	cin >> c1 >> s1 >> c2 >> s2;
	string t1 = "",t2 = "";
	t1 += s1[0] + s1[1];
	t2 += s2[0] + s2[1];
	char a1 = s1[2],a2 = s2[2];
	string k = "";
	k += a1 + a2;
	if(c1 == c2) cout << 1;
	else cout << 0;
	if(c1 == c2 && t1 == t2) cout << 1;
	else cout << 0;
	bool flag = 0;
	if((a1 >= 'A' && a1 <= 'C' && a2 >= 'A' && a2 <= 'C') || (a1 >= 'D' && a1 <= 'F' && a2 >= 'D' && a2 <= 'F'))
		flag = 1;
	if(c1 == c2 && t1 == t2 && flag) cout << 1;
	else cout << 0;
	bool tag = 0;
	if(k == "AB" || k == "BA" || k == "BC" || k == "CB" || k == "DF" || k == "FD") 
		tag = 1;
	if(c1 == c2 && t1 == t2 && flag && tag) cout << 1;
	else cout << 0;
	return 0;
}
