#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

using lnt = long long;

void Solve()
{
	int tmp_1, tmp_3;
	string tmp_2, tmp_4;
	cin >> tmp_1 >> tmp_2 >> tmp_3 >> tmp_4;
	int x_1 = (tmp_2[0]-'0')*10 + (tmp_2[1]-'0'), y_1 = tmp_2[2]-'A';
	int x_2 = (tmp_4[0]-'0')*10 + (tmp_4[1]-'0'), y_2 = tmp_4[2]-'A';
	if (y_1 > y_2) swap(y_1,y_2);
	bool flag = true;
	if (tmp_1 == tmp_3) cout << 1;
	else cout << 0, flag = false;
	if (x_1 == x_2 && flag) cout << 1;
	else cout << 0, flag = false;
	if (((y_1 <= 2 && y_2 <= 2) || (y_1 >= 3 && y_2 >= 3)) && flag) cout << 1;
	else cout << 0, flag = false;
	if (y_2-y_1 == 1 && flag) cout << 1;
	else cout << 0; 
	
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; //cin >> T;
	while (T--) Solve();
	return 0;
}
