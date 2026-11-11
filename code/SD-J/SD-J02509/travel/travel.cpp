#include<bits/stdc++.h>
using namespace std;
string s1="",s2="",ans="0000";
int a,b;
bool cmp1() {
	return s1[0]+s1[1]==s2[0]+s2[1];
}
bool cmp2() {
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')) return 1;
	else return 0;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>a>>s1>>b>>s2;
	if(a==b) {
		ans[0]='1';
		if(cmp1()) {
			ans[1]='1';
			if(cmp2()) {
				ans[2]='1';
				int i=abs(s1[2]-s2[2]);
				if(i==1){
					ans[3]='1';
				}
			}
		}
	}
	cout<<""<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
