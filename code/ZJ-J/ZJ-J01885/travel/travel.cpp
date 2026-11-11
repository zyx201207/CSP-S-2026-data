#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans1=0,ans2=0,ans3=0,ans4=0;
int turn=0;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) {
		ans1=0;
		ans2=0;
		ans3=0;
		ans4=0;
	} else if(s1[0]==s2[0] && s1[1]==s2[1]) {
		ans1=1;
		ans2=1;
	}
	if(ans2==1) {
		if(s2[2]-'A'+65<68 && s1[2]-'A'+65<68) {
			ans3=1;
		}
		if(s2[2]-'A'+65>67 && s1[2]-'A'+65>67) {
			ans3=1;
			turn=1;
		}
	}
	if(ans3==1) {
		if(turn==0) {
			if(s2[2]-'A'+65+1==s1[2]-'A'+65 || s2[2]-'A'+65-1==s1[2]-'A'+65) {
				ans4=1;
			}
		}
		else{
			if(s2[2]-'A'+65+2==s1[2]-'A'+65 || s2[2]-'A'+65-2==s1[2]-'A'+65){
				ans4=1;
			}
		}

	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}