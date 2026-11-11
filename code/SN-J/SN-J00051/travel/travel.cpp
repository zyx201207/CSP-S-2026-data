#include<bits/stdc++.h>
using namespace std;

char sits[6] = {'A','B','C',' ','D','F'};
string c1,s1,c2,s2;
int main()
{
	freopen("travel1.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	bool same = false;
	char r1,r2,a1,a2;
	r1 = c1[0];r2 = c1[1];
	a1 = c2[0];a2 = c2[1];
	if(r1==a1&&r2==a2) same = true;
	if(same){
		cout << 1;
		char x1,y1,x2,y2;
		x1 = s1[0];y1 = s1[1];
		x2 = s2[0];y2 = s2[1];
		if(x1 == x2 && y1 == y2){
			cout << 1;
			char x3 = s1[2];
			char y3 = s2[2];
			int sit1,sit2;
			for(int i = 0;i < 6;i++){
				if(sits [i] == x3) sit1 = i;
				if(sits [i] == y3) sit2 = i;
			}
			if((sit1>=0&&sit1<=2&&sit2>=0&&sit2<=2)||(sit1>=4&&sit1<=5)&&(sit2>=4&&sit2<=5)){
				cout << 1;
				int ax = max(sit1,sit2);
				int in = min(sit1,sit2);
				int t = ax-in;
				if(t == 1){
					cout << 1;return 0;
				}else{
					cout << 0;return 0;
				}
			} else {
				cout << "00";
				return 0;
			}
		} else {
			cout << "000";
			return 0;
		}
	}else if(!same){
		cout << "0000";
		return 0;
	}
	return 0;
} 
