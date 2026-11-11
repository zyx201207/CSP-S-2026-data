#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			char t1=s1[2],t2=s2[2];
			if((t1<='C'&&t2<='C')
			||(t1>='D'&&t2>='D')){
				cout<<1;
				int v1=t1,v2=t2;
				if(abs(v1-v2)==1){
					cout<<1;
				}
				else cout<<0;
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
	else cout<<"0000";
	return 0;
}
