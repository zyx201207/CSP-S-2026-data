#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string t1="";
		string t2="";
		t1=t1+s1[0]+s1[1];
		t2=t2+s2[0]+s2[1];
		if(t1==t2){
			cout<<1;
			char t1=s1[2];
			char t2=s2[2];
			if((t1>='D'&&t2>='D')||(t1>='A'&&t1<='C'&&t2>='A'&&t2<='C')){
				cout<<1;
				if(t1+1==t2||t1-1==t2){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
