#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>c2>>s1>>s2;
	cout<<(c1==s1)<<(c1==s1 && c2[0]*10+c2[1]==s2[0]*10+s2[1])<<(c1==s1 && c2[0]*10+c2[1]==s2[0]*10+s2[1] && ((min(s2[2],c2[2])=='D' && max(s2[2],c2[2])=='E') || (min(s2[2],c2[2])>='A' && max(s2[2],c2[2])<='C')))<<(c1==s1 && c2[0]*10+c2[1]==s2[0]*10+s2[1] && ((min(s2[2],c2[2])=='D' && max(s2[2],c2[2])=='E') || (min(s2[2],c2[2])>='A' && max(s2[2],c2[2])<='C')) && abs(int(c2[2]-s2[2]))==1);
	return 0;
}
