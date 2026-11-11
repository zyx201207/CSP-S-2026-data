#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5],ans[10]= {'0','0','0','0','0','0','0','0','0','0'};
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]) {
		ans[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
			ans[1]='1';
			if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A') {
				ans[2]='1';
				if(s1[2]+1==s2[2]||s2[2]+1==s1[2]) {
					ans[3]='1';
				}
			}
			if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D') {
				ans[2]='1';
				ans[3]='1';
			}
		}
	}
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	return 0;
}
