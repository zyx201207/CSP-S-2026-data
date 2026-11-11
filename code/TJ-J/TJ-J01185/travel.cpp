#include <bits/stdc++.h>
using namespace std;

int main(){

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	// 第一个判断
	if (c1 == c2){
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	// 第二个判断
	int s1_pai = 0, s2_pai = 0;
	int len = s1.size();
	for (int i = 0;i < len - 1;i++){
        s1_pai = s1_pai * 10 + (s1[i] - '0');
	}
	int len2 = s2.size();
	for (int i = 0;i < len2 - 1;i++){
        s2_pai = s2_pai * 10 + (s2[i] - '0');
	}
	if (s1_pai == s2_pai){
        cout << 1;
	} else {
        cout << "000";
        return 0;
	}
	// 第三个判断
    char s1_lie = s1[len - 1], s2_lie = s2[len2 - 1];
    bool DE = (s1_lie == 'D' && s2_lie == 'E') || (s1_lie == 'E' && s2_lie == 'D');
    bool ABC = (s1_lie == 'A' && s2_lie == 'B') || (s1_lie == 'B' && s2_lie == 'A') || (s1_lie == 'A' && s2_lie == 'C') || (s1_lie == 'C' && s2_lie == 'A') || (s1_lie == 'B' && s2_lie == 'C') || (s1_lie == 'C' && s2_lie == 'B');
    if (ABC || DE){
        cout << 1;
    } else {
        cout << "00";
        return 0;
    }
	// 第四个判断
	int cha = int(s1_lie - s2_lie);
	int abs_cha = abs(cha);
	if (abs_cha == 1){
        cout << 1;
	} else {
        cout << "0";
        return 0;
	}

	return 0;
}

