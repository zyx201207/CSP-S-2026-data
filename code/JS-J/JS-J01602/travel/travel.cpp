#include<bits/stdc++.h>
using namespace std;

#define int long long
string c1,s1,c2,s2;
int sameSide[100][100]=
{/*       a,b,c,d,e,f*/
	/*a*/{1,1,1,0,0,0},
	/*b*/{1,1,1,0,0,0},
	/*c*/{1,1,1,0,0,0},
	/*d*/{0,0,0,1,0,1},
	/*e*/{0,0,0,0,0,0},
	/*f*/{0,0,0,1,0,1}
};
int near[100][100]=
{/*       a,b,c,d,e,f*/
	/*a*/{0,1,0,0,0,0},
	/*b*/{1,0,1,0,0,0},
	/*c*/{0,1,0,0,0,0},
	/*d*/{0,0,0,0,0,1},
	/*e*/{0,0,0,0,0,0},
	/*f*/{0,0,0,1,0,0}
};
signed main(){
	freopen("travel.in" ,"r",stdin );
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[1]==s2[1]&&s1[0]==s2[0]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(sameSide[(s1[2]-'A')][s2[2]-'A']){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(near[(s1[2]-'A')][s2[2]-'A']){
		cout<<1;
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
/*wo yao hui jia da DX*/
