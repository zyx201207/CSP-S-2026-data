#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int a1=s1[2],a2=s2[2];
	if(c1==c2){
		cout<<'1';
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<'1';
			int b1=a1-'C',b2=a2-'C';
			if(b1<=0 && b2<=0){
				cout<<'1';
			}else if(b1>0 && b2>0){
				cout<<'1';
			}else{
				cout<<"00";
				return 0;
			}
			if(abs(b1-b2)==1){
				cout<<'1';
			}else cout<<'0';
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
