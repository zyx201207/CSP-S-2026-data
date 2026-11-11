#include <bits/stdc++.h>

using namespace std;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool flag=true;
	if(c1==c2) cout<<flag;
	else flag=false,cout<<flag;
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<flag;
	else flag=false,cout<<flag;
	int a=(int)s1[2]-'A'+1;
	int b=(int)s2[2]-'A'+1;
	
	if((a<=3&&b<=3)||(a>=4&&b>=4)) cout<<flag;
	else flag=false,cout<<flag;
	if(abs(a-b)==1&&((a!=3&&b!=4)||(a!=4&&b!=3))) cout<<flag;
	else flag=false,cout<<flag;
	return 0;
}
