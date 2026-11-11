#include<bits/stdc++.h>
using namespace std;
int t1, t2, x1, x2, y1, y2;
char c1, c2; 

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> t1 >> x1 >> c1 >> t2 >> x2 >> c2;
	y1 = c1 - 'A' + 1; y2 = c2 - 'A' + 1; 
	if(t1==t2){
		cout << 1;
		if(x1==x2){
			cout << 1;
			if((y1<=3&&y2<=3) || (y1>=4&&y2>=4)){
				cout << 1;
				if((y1+1==y2) || (y2+1==y1)){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
