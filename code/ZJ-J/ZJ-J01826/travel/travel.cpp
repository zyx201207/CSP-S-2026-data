#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			int x=0,y=0;
			if(s1[2]>='A'&&s1[2]<='C')x=1;
			if(s2[2]>='A'&&s2[2]<='C')y=1;
			if(x==y){
				if(x==1&&y==1&&abs((int)s1[2]-s2[2])==1)cout<<"1111";
				else if(x==0&&y==0)cout<<"1111";
				else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
}
