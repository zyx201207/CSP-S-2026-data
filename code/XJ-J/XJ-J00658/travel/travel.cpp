#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("rtavel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	string a1,a2,b1,b2;
	cin >> a1 >> a2 >> b1 >> b2;
	cin >> c1 >> c2 >> s1 >> s2;
	for(int i = 2;i <= 15;i++){
		if(c1 == s1){
			cout << '1';
		}else {
			cout << '0';
		}
		for(int i = 1;i <= 18;i++){
		if(a1 == b1){
			cout << '1';
		}else{
			cout << '0';
		}
		for(int i = 1;i <= 5;i++){
		if(a2 == b2){
			cout << '1';
		}else {
			cout << '0';
		}
		for(int i = 1;i<= 2;i++){
		
		if(s2-1 == c2 || s2 + 1 == c2){
			cout << '1';
		}else {
			cout << '0';
		}
				}
			}
		}
	}
	return 0;
}