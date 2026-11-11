#include<bits/stdc++.h>
using namespace std;
#define I ios::sync_with_stdio(false);
#define AK cin.tie(0);
#define CSP cout.tie(0);
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	I AK CSP
	string c1 , z1 , c2 , z2;
	cin >> c1 >> z1 >> c2 >> z2;
	cout<<(c1 == c2?1:0);
	cout<<((c1 == c2?1:0)&&z1.substr(0 , 2) == z2.substr(0 , 2)?1:0);
	cout<<((c1 == c2?1:0)&&z1.substr(0 , 2) == z2.substr(0 , 2)&&((z1[2] >= 'A'&&z1[2] <= 'C'&&z2[2] >= 'A'&&z2[2] <= 'C')||(z1[2] >= 'D'&&z1[2] <= 'F'&&z2[2] >= 'D'&&z2[2] <= 'F')?1:0));
	cout<<((c1 == c2?1:0)&&z1.substr(0 , 2) == z2.substr(0 , 2)&&((z1[2] >= 'A'&&z1[2] <= 'C'&&z2[2] >= 'A'&&z2[2] <= 'C')||(z1[2] >= 'D'&&z1[2] <= 'F'&&z2[2] >= 'D'&&z2[2] <= 'F')&&((z1[2] == z2[2]+1||z1[2] == z2[2]-1)||(z1[2] == 'D'&&z2[2] == 'F')||(z1[2] == 'F'&&z2[2] == 'D')))?1:0);
	return 0;
}
