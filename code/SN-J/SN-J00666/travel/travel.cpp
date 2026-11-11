//Kong Chenfeng xi'an shi han guang zhong xue SN-J00666
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rz,xc,xz;
	cin>>rc>>rz>>xc>>xz;
	string sr="",sx="";
	for(int i=0;i<2;i++){
		sr+=rz[i],sx+=xz[i];
	}
	string ans="";
	if(rc==xc){
		ans+='1';
		if(sr==sx){
			ans+='1';
			if(rz[2]>='A'&&rz[2]<='C'&&xz[2]>='A'&&xz[2]<='C'){
				ans+='1';
				if(rz[2]+1==xz[2]||rz[2]-1==xz[2]){
					ans+='1';
				}else{
					ans+='0';
				}
			}else if((rz[2]=='D'||rz[2]=='F')&&(xz[2]=='D'||xz[2]=='F')){
				ans+="11";
			}else{
				ans+="00";
			}
		}else{
			ans+="000";
		}
	}else{
		cout<<"0000"<<endl;
	}
	cout<<ans;
	return 0;
}
