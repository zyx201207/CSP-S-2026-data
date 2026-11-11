#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<0<<0<<0<<0;
	}else{
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if((s1[2]!='D'&&s1[2]!='F'&&s2[2]!='D'&&s2[2]!='F')){
				if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
					cout<<1111;
				}else{
					cout<<1110;
				}
			}else{
				if(s1[2]=='D'&&s2[2]=='F'){
					cout<<1111;
				}else{
					cout<<1100;
				}
			}
		}else{
			cout<<1000;
		}
	}
	return 0;
}
