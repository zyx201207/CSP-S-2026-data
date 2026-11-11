#include <iostream>
#define ioss ios::sync_with_stdio(0);cin.tie(0);
#define ret return
#define ll long long
using namespace std;
string c1,s1,c2,s2;
string ans="";
int main(){
	ioss
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+="1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans+="1";
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				ans+="1";
				int c=abs((int)(s1[2]-s2[2]));
				if(c==1){
					ans+="1";
				}else{
					ans+="0";
				}
			}else{
				ans+="00";
			}
		}else{
			ans+="000";
		}
	}else{
		ans+="0000";
	}
	cout<<ans;
	return 0;
}