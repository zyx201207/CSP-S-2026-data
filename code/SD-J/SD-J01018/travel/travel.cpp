#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define ull unsigned long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,cc;
	string s,ss;
	cin>>c>>s>>cc>>ss;
	if(c!=cc){
		cout<<"0000";
		return 0;
	}
	int ps=s[0]*10+s[1],pss=ss[0]*10+ss[1];
	if(ps!=pss){
		cout<<"1000";
		return 0;
	}
	if(!(s[2]<='C' and ss[2]<='C') and !(s[2]>='D' and ss[2]>='D')){
		cout<<"1100";
		return 0;
	}
	if(ss[2]-s[2]==1 or ss[2]-s[2]==-1){
		cout<<"1111";
		return 0;
	}
	else{
		cout<<"1110";
		return 0;
	}
    return 0;
}

