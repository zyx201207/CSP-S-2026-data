#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
bool r1,r2;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+="1";
		string t1,t2;
		t1=s1[0]+s1[1];
		t2=s2[0]+s2[1];
		if(t1==t2){
			ans+="1";
			r1=true;
		}else ans+="0";
		if(r1==true&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))){
			ans+="1";
			r2=true;
		}else ans+="0";	
		if(r1==true&&r2==true&&(s1[2]+1==s2[2]||s1[2]-1==s2[2]))ans+="1";
		else ans+="0";
	}else ans="0000";
	cout<<ans<<'\n';
	return 0;
}
