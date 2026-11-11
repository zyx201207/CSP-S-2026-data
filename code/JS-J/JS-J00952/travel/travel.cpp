#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=int(s1[2]),b=int(s2[2]);
	if(c1==c2){
		cout<<1;
		if(s1[1]==s2[1]){
			cout<<1;
			if(s1[2]=='C'&&s2[2]=='D'){
				cout<<0<<0;
			}else if(s1[2]=='C'&&s2[2]=='D'){
				cout<<0<<0;
			}else{
				cout<<1;
				if(a-b==1||b-a==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
