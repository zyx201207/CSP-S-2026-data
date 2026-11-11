#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c1,s1,c2,s2;
	char ss1,ss2;
	cin >>c1>>s1>>ss1>>c2>>s2>>ss2;
	if(c1==c2){
		cout <<"1";
		if(s1==s2){
			cout <<"1";
			if((ss1<='C'&&ss2<='C')||(ss1>='D'&&ss2>='D')){
				cout <<"1";
				if(abs(ss1-ss2)==1&&!((ss1=='C'&&ss2=='D')||(ss1=='D'&&ss2=='C'))) cout <<"1";
				else cout <<"0";
			}else cout <<"00";
		}else cout <<"000";
	}else cout <<"0000";
	
	return 0;
}
