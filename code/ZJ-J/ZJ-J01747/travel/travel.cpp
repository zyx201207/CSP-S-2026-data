#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	int s1_1=s1[0]-48;
	int s1_2=s1[1]-48;
	int s2_1=s2[0]-48;
	int s2_2=s2[1]-48;
	if(s1_1==s2_1 && s1_2==s2_2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char s1zuo=s1[2];
	char s2zuo=s2[2];
	if(s1zuo=='A' || s1zuo=='B' || s1zuo=='C'){
		if(s2zuo=='A' || s2zuo=='B' || s2zuo=='C'){
			cout<<1;
			if((s1zuo-s2zuo)==1 || (s1zuo-s2zuo)==-1){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		if(s2zuo=='D' || s2zuo=='F'){
			cout<<11;
		}else{
			cout<<"00";
			return 0;
		}
	}
	return 0;
}
