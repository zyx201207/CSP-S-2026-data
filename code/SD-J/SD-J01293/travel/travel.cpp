#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char za,zb;
	scanf("%d %d%c %d %d%c",&a,&b,&za,&c,&d,&zb);
	if(a!=c) {
		cout <<"0000";
		return 0;
	} else { //在同一车厢
		cout <<1;
		if(b!=d) {
			cout <<"000";
			return 0;
		} else {//在同一排 5
			cout <<1;
			if((za<='C'&&zb>='D')||(za>='D'&&zb<='C')) {
				cout <<"00";
				return 0;
			}
			else//在同一侧 
			{
				cout <<"1";
				if((za=='A'&&zb=='B')||(za=='B'&&zb=='A')||(za=='B'&&zb=='C')||(za=='C'&&zb=='B')||(za=='D'&&zb=='F')||(za=='F'&&zb=='D'))
				{
					cout <<1;
				 } 
				 else
				 {
				 	cout <<0;
				 }
			}
		}
	}
	return 0;
}
