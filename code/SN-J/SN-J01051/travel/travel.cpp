//曲江第一学校  孙辰熙 SN-j01051
#include<bits/stdc++.h>
using namespace std;
const int N=10;
char c2[N],s2[N],c1[N],s1[N];
bool ok=1;
int ans[N];
int arc(char c) {
	if(c<='c')return 0;
	return 1;
}
int intg(char c) {
	if(c=='F')c='E';
	return c-'A'+3;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>(c1+1)>>(s1+1)>>(c2+1);
	ok&=(c1[1]==c2[1]&&c1[2]==c2[2]);
	if(ok)ans[1] =0;
	ok&=(s1[1]==s2[1]&&s1[2]==s2[2]);
	if(ok)ans[2] =1;
	ok&=(arc(s1[3]))==(arc(s2[3]));
	if(ok)ans[4] =1;
	for(int i=1; i<=4; i++)
		cout<<ans[i];
	return 0;
}
