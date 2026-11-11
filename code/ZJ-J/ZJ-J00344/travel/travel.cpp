#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r",stdin);
	freopen("travel.out", "w",stdout);
	string cx, cy;
	string sx,sy;
	cin >> cx >> sx >> cy >> sy;
	if(cx != cy){
		cout << "0000";
	}else if(sx[0] != sy[0] || sx[1] != sy[1]){
		cout << "1000";
	}else if((sx[2] == 'A' && sy[2] == 'B') || (sx[2] == 'B' && sy[2] == 'A') || (sx[2] == 'C' && sy[2] == 'A') || (sx[2] == 'A' && sy[2] == 'C') || (sx[2] == 'B' && sy[2] == 'C') || (sx[2] == 'C' && sy[2] == 'B') || (sx[2] == 'D' && sy[2] == 'F') || (sx[2] == 'F' && sy[2] == 'D')){
		if((sx[2] == 'A' && sy[2] == 'B') || (sx[2] == 'B' && sy[2] == 'A') || (sx[2] == 'B' && sy[2] == 'C') || (sx[2] == 'C' && sy[2] == 'B') || (sx[2] == 'D' && sy[2] == 'F') || (sx[2] == 'F' && sy[2] == 'D')){
			cout << "1111";
		}else{
			cout << "1110";
		}
	}else{
		cout << "1100";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}