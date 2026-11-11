#include<iostream>
#include<cmath>
using namespace std;
string c1,s1,c2,s2;
bool ans[4];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]=1;
	}
	if(ans[0]==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		ans[1]=1;
	}
	if(ans[1]==1&&((s1[2]>'C'&&s2[2]>'C')||(s1[2]<='C'&&s2[2]<='C'))){
		ans[2]=1;
	}
	if(ans[2]==1&&((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')||abs(s1[2]-s2[2])==1)){
		ans[3]=1;
	}
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	return 0;
}
