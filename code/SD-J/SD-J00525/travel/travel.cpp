#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	string c,d;
	cin >> a >> c >> b >> d;
	if(a != b){
		cout << "0000";
		return 0;
	} else {
		int li1 = (c[0]-48)*10 + (c[1]-48);
		int li2 = (d[0]-48)*10 + (d[1]-48);
		if(li1 != li2){
			cout << "1000";
			return 0;
		} else {
			char seat1 = c[2],seat2 = d[2];
			if(!(seat1=='A'&&seat2=='B'||seat1=='B'&&
			seat2=='C'||seat1=='A'&&seat2=='C'|| seat1=='B'&&
			seat2=='A'||seat1=='C'&&seat2=='A'||seat1=='C'&&seat2=='B'||
			seat1=='D'&&seat2=='F'||seat1=='F'&&seat2=='D')){
				cout << "1100";
				return 0;
			} else {
				if(!(seat1=='A'&&seat2=='B'||seat1=='B'&&
				seat2=='C'||seat1=='D'&&seat2=='F'||seat1=='F'&&seat2=='D')){
					cout << "1110";
					return 0;
				} else {
					cout << "1111";
					return 0;
				}
			}
		}
	}
	return 0;
}
