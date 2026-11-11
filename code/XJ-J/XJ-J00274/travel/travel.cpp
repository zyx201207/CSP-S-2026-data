#include <bits/stdc++.h> 
using namespace std;

#define sp ' '
#define endl '\n'

typedef long long ll;
typedef __int128 i128;

typedef vector <int> vi;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	char is0[5], is1[5], is2[5], is3[5];
	scanf("%s%s%s%s", is0, is1, is2, is3);
	
	string s0 = is0, s1 = is1, s2 = is2, s3 = is3;
	int a = stoi(s0), b = stoi(s1.substr(0, 2)), d = stoi(s2), e = stoi(s3.substr(0, 2));
	char c = s1[2], f = s3[2];
	
//	cout << a << sp << b << sp << c << sp << d << sp << e << sp << f << endl;
	
	if (c > f)
	    swap(c, f);
	    
	printf("%d%d%d%d\n", (a == d),  (a == d && b == e),  ((a == d && b == e) && ((c <= 'C' && f <= 'C') || (c > 'C' && f > 'C'))),  (((a == d && b == e) && ((c <= 'C' && f <= 'C') || (c > 'C' && f > 'C'))) && ((c == 'A' && f == 'B') || (c == 'B' && f == 'C') || (c == 'D' && f == 'F'))));
	  
	 
	fclose(stdin),
	fclose(stdout);
	return 0;
}
