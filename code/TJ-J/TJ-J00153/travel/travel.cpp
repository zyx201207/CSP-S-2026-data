#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r,r1,x,x1;
	string ans;
	cin>>r>>r1>>x>>x1;
	
	int rx=(r[0]-'0')*10+(r[1]-'0');
	int xx=(x[0]-'0')*10+(x[1]-'0');
	int rh=(r1[0]-'0')*10+(r1[1]-'0');
	int rl=r1[2]-'A'+1;
	int xh=(x1[0]-'0')*10+(x1[1]-'0');
	int xl=x1[2]-'A'+1;
//	cout<<rx;///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if(rx == xx){
		if(rh == xh){
			if(rl<4 && xl<4){
				if(rl==xl+1 || xl==rl+1){
					ans="1111";
				}else{
					ans="1110";
				}
			}else if(rl>3 && xl>3){
				ans="1111";
			}else{
				ans="1100";
			}
		}else{
			ans="1000";
		}
	}else{
		ans="0000";
	}
	
	cout<<ans;
	
	return 0;
} 
