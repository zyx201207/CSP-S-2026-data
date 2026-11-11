#include<bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		int x1, x2;
		x1 = s1[0] - '0' * 10 + s1[1] - '0';
		x2 = s2[0] - '0' * 10 + s2[1] - '0';
		if(x1 == x2){
			bool f = 0;
			cout << 1;
			char t1, t2; t1 = s1[2], t2 = s2[2];
			if(t1 == 'A' || t1 == 'B' || t1 == 'C'){
				if(t2 == 'A' || t2 == 'B' || t2 == 'C') f = 1;
			} else{//C»òD  
				if(t2 == 'D' || t2 == 'F') f = 1;
			}
			if(f == 1){
				cout << 1;
				int tmp1 = t1 - '0', tmp2 = t2 - '0';
				if(abs(tmp1 - tmp2) == 1) cout << 1;
				else cout << 0;
			}else cout << 0 << 0;
		}
		else cout << 0 << 0 << 0;
	}
	else cout << 0 << 0 << 0 << 0;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
