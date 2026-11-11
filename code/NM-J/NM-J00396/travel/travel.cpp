#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	char zhi;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<1;
		string a=s1.substr(0,2),b=s2.substr(0,2);
		if(a!=b){
			cout<<"000";
		}else{
			cout<<1;
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
				cout<<1;
				if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
					int x=s1[2]-'0'-(s2[2]-'0');
					if(x==1||x==-1){
						cout<<1;
					}else{
						cout<<0;
					}
				}else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
					cout<<1;
				}
			}else{
				cout<<"00";
			}
		}
	}
	return 0;
}
