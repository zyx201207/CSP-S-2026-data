#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	bool flag_p=0;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			flag_p=1;
			break;
		}
	}
	if(flag_p){
		cout<<"000";
		return 0;
	}
	else cout<<1;
	bool l1=0,l2=0,r1=0,r2=0;
	if(s1[2]=='D'||s1[2]=='F') r1=1;
	else l1=1;
	if(s2[2]=='D'||s2[2]=='F') r2=1;
	else l2=1;
	if((l1&&l2)||(r1&&r2)) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
}
