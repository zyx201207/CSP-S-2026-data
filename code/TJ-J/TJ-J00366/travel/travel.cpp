#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout <<"1";
		bool flag = 1;
		for(int i = 0;i < 2;i++){
			if(s1[i]!=s2[i]) flag = 0;
		}
		if(flag == 1){
			cout <<"1";
			if(s1[2]<=67&&s2[2]<=67){
				cout<<"1";
				if(s1[2]==65&&s2[2]==66||s1[2]==66&&s2[2]==65||s1[2]==66&&s2[2]==67||s1[2]==67&&s2[2]==66){
					cout <<"1";
				}else{
					cout <<"0";
				}
				return 0;
			}else{
				cout <<"00";
				return 0;
			}
			if(s1[2]>=68&&s2[2]>=68){
				cout<<"11";
			}else{
				cout <<"00";
			}
		}else{
			cout <<"000";
			return 0;
		}		
	}else{
		cout <<"0000";
		return 0;
	}
	return 0;
} 
