#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,ans="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){ans[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[1]='1';
			if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C')){
				ans[2]='1';
				if(abs(int(s1[2]-s2[2]))==1)ans[3]='1';
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
