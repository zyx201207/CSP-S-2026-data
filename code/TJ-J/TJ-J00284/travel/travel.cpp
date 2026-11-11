#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	string h1,h2;
	for(int i = 0;i < 2;i++)
	{
		h1 += s2[i];
		h2 += s4[i];
	}
	char z1 = s2[s2.size()-1];
	char z2 = s4[s4.size()-1];
	if(s1 == s3)
		cout << 1;
	else cout << 0;
	
	if(h1 == h2 && s1 == s3) 
		cout << 1;
	else cout << 0;
	
	if((z1 == 'A' && z2 == 'B' || z1 == 'A' && z2 == 'C' || z1 == 'D' && z1 == 'F' || z1 == 'B' && z2 == 'C' || z2 == 'A' && z1 == 'B' || z2 == 'A' && z1 == 'C' || z2 == 'D' && z1 == 'F' || z2 == 'B' && z1 == 'C') && s1 == s3 && h1 == h2)
		cout << 1;
	else cout << 0;
	
	if(abs(z1 -z2) == 1 && !((z1 == 'C' && z2 == 'D')|| (z1 == 'D' && z2 == 'C'))&& s1 == s3 && h1 == h2)
		cout << 1;
	else cout << 0;
 } 
