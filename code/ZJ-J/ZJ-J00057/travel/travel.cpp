#include <bits/stdc++.h>
using namespace std;

int ca,cb;
string sf,ss;

bool ans[4];

int db(char c){
	if(c=='D') c='E';
	return c-'A';
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	
	cin>>ca>>sf>>cb>>ss;
	
	if(ca==cb){
		ans[0]=1;
		if(sf.substr(0,2)==ss.substr(0,2)){
			ans[1]=1;
			if((db(sf[2])<=2&&db(ss[2])<=2)||(db(sf[2])>=3&&db(ss[2])>=3)){
				ans[2]=1;
				if(abs(db(sf[2])-db(ss[2]))==1){
					ans[3]=1;
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		if(ans[i]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	
	return 0;
}