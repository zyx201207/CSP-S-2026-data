#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,m1,m2,l1,l2;
	cin>>s1>>m1>>s2>>m2;
	l1=m1[0]+m1[1];
	l2=m2[0]+m2[1];
	if (s1== s2){
		cout<<1;
		if (l1 == l2){
			cout<<1;
			if (max(m1[2],m2[2])<'D'){
				cout<<1;
				if (m1[2]+1 == m2[2] || m2[2]+1 == m1[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if (min(m1[2],m2[2])>'C'){
				cout<<1;
				if (m1[2]+1 == m2[2] || m2[2]+1 == m1[2]){
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
