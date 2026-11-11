#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string t1=s1.substr(0,2);
		string t2=s2.substr(0,2);
		if(t1==t2){
			cout<<1;
			t1=s1[2];
			t2=s2[2];
			if((t1>="D"&&t2>="D")||(t1<="C"&&t2<="C")){
				cout<<1;
				if(t1>t2){
					string t=t1;
					t1=t2;
					t2=t;
				}
				if((t1=="A"&&t2=="B")||(t1=="B"&&t2=="C")||(t1=="D"||t2=="F")){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}

