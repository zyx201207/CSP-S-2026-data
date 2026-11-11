#include<bits/stdc++.h>
using namespace std;
int c1,c2,a,b;
char s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> a >> s1 >> c2 >> b >> s2;
	if(c1 == c2) cout << 1;
	else cout << 0;
	if(c1 == c2 && a == b) cout << 1;
	else cout << 0;
	if(c1 == c2 && a == b && ( ((s1 == 'A' || s1 == 'B' || s1 == 'C') && (s2 == 'A' || s2 == 'B' || s2 == 'C')) || ( (s1 == 'D' || s1 == 'E') && (s2 == 'D' || s2 == 'E') ) )) cout << 1;
	else cout << 0;
	if(c1 == c2 && a == b && ((s1 == 'A' && s2 == 'B') || (s1 == 'B' && (s2 == 'A' || s2 == 'C')) || (s1 == 'C' && s2 == 'B') || (s1 == 'D' && s2 == 'E') || (s1 == 'E' && s2 == 'D'))) cout << 1;
	else cout << 0;
	return 0;
}
