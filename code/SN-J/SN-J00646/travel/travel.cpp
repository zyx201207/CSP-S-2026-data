//吕思齐  西安翱翔中学  SN-J00646
#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2) printf("1");
	else printf("0");
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) printf("1");
	else printf("0");
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C'))) printf("1");
	else printf("0");
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C'))
	&& abs(s1[2]-s2[2]) == 1) printf("1");
	else printf("0");
	return 0;
}
