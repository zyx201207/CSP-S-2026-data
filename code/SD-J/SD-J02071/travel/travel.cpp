#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

string a, b, c, d; 
char pos[5] = {'A', 'B', 'C', 'D', 'E'};
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> a >> b >> c >> d;
	bool q1 = false, q2 = false, q3 = false, q4 = false;
	if(a == c){
		q1 = true;
		if(b.at(0) == d.at(0) && b.at(1) == d.at(1)){
			q2 = true;
			int pos1, pos2;
			for(int i = 0;i <= 4;i++){
				if(b[2] == pos[i]) pos1 = i;
				if(d[2] == pos[i]) pos2 = i;
			}
			if((pos1 <= 2 && pos2 <= 2) || (pos1 > 2 && pos2 > 2)){
				q3 =  true;
				int dis = abs(pos1 - pos2);
				if(dis == 1){q4 = true;}
			}
		}
	}
	cout << q1 << q2 << q3 << q4;
	return 0;
}
