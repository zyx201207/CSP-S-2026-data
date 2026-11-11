#include <bits/stdc++.h>
#define ll long long
#define IO freopen("travel.in","r",stdin),freopen("travel.out","w",stdout)
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pqu priority_queue

#define lowbit(x) ((x) & (-x))

using namespace std;

char s1,s2;
int c1,c2,c3,c4;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	IO;
	cin >> c1 >> c2 >> s1 >> c3 >> c4 >> s2;
	
	//cout << c1 << ' ' << c2 << ' ' << s1 << ' ' << c3 << ' ' << c4 << ' ' << s2 << '\n';
	if(c1 == c3){
		cout << 1;
		if(c2 == c4){
			cout << 1;
			if((s1 <= 'C' && s2 <= 'C') || (s1 >= 'D' && s2 >= 'D')){
				cout << 1;
				if((s1 == 'F' && s2 == 'D') || (s1 == 'F' && s2 == 'D') || (s1 == 'A' && s2 == 'B') || (s1 == 'B' && s2 == 'A')){
					cout << 1;
				}
				else if((s1 == 'C' && s2 == 'B') || (s1 == 'B' && s2 == 'C')){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else{
				cout << 0;
				cout << 0;
			}	
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	
	return 0;
}

//start time: 16:30
//end time: 20:00

//CSP-J 2026 JX
//do not forget to add freopen!

//diff /home/noi/CSP-J00594/travel/travel.out /home/noi/CSP-J00594/travel/travel3.ans
