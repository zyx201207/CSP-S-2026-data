#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cx, yp, yc, xl;
string c1, c2, s1, s2;
string zw1 = "", zw2 = "";
int zf1, zf2;
void aaa(){
	for(int i = 0; i <= 2; i++){
		if(i <= 1){
			zw1 += s1[i];
			zw2 += s2[i];
		}else{
			zf1 = s1[i] - 'A';
			zf2 = s2[i] - 'A';
		}
	}
}
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	aaa();
	if(c1 == c2){
		cx = 1;
		if(zw1 == zw2){
			yp = 1;
			if((zf1 <= 2 && zf2 <= 2) || (zf1 > 2 && zf2 > 2)){
				yc = 1;
				if(zf1 - 1 == zf2 || zf2 - 1 == zf1){
					xl = 1;
				}
			}
		}
	}
	if(cx){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(yp){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(yc){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(xl){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}