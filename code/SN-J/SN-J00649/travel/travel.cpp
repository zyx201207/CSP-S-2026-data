//黄伟豪 西安市铁一中学 SN-J00649 
#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2;
char ss1,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	cin>>c1>>s1>>ss1>>c2>>s2>>ss2;
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if((ss1>='A'&&ss1<='C'&&ss2>='A'&&ss2<='C')||((ss1=='D'||ss1=='F')&&(ss2=='D'||ss2=='F'))){
				cout<<1;
				if(abs(ss1-ss2)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
