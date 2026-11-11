#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
string c1,s1,c2,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		ans="0000";
	}else if(s1.substr(0,2)==s2.substr(0,2)){
		char a=s1[2],b=s2[2];
		if(a<='C'&&b<='C'||a>='D'&&b>='D'){
			if(a>b)swap(a,b);
			if(b-a==1)ans="1111";
			else ans="1110";
		}else{
			ans="1100";
		}
	}else{
		ans="1000";
	}cout<<ans<<"\n";
	return 0;
}
