#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ans="";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		ans+="1";
		string pai1="",pai2="";
		char lie1,lie2;
		pai1+=s1[0]+s1[1];
		pai2+=s2[0]+s2[1];
		lie1=s1[2];
		lie2=s2[2];
		if(pai1==pai2) {
			ans+="1";
			if(((lie1<='C'&&lie2<='C')||(lie1>='D'&&lie2>='D'))&&pai1==pai2){
				ans+="1";
				if(lie1+1==lie2||lie2+1==lie1){
					ans+="1";
				}else ans+="0";
			} else ans+="00";
		} else ans+="000";
	} else {
		ans+="0000";
	}
	cout<<ans;
	return 0;
}
