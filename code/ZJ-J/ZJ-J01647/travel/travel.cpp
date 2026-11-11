#include<bits/stdc++.h>
using namespace std;

namespace wsrCSPJ {
	int main() {
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int c1,c2;
		string s1,s2;
		cin>>c1>>s1>>c2>>s2;
		bool ans1,ans2,ans3,ans4;
		// problem 1
		if(c1==c2) ans1=1;
		else ans1=0;
		// problem 2
		if(ans1&&s1[0]==s2[0]&&s1[1]==s2[1]) ans2=1;
		else ans2=0;
		// problem 3
		if(ans2&&
		((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))) ans3=1;
		else ans3=0;
		// problem 4
		if(ans3&&(abs(s1[2]-s2[2])==1||(s1[2]=='D'&&s2[2]=='F'))) ans4=1;
		else ans4=0;
		cout<<ans1<<ans2<<ans3<<ans4;
		return 0;
	}
}

int main() { return wsrCSPJ::main(); }

