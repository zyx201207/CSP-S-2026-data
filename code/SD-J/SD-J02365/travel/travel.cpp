#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int c1,c2;
int d1,d2;
string s1,s2;
int pan(){
	if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')) return true;
	if((s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')) return true;
	return false;
}
int pan2(char a,char b){
	if(a>b) swap(a,b);
	if(a=='A'&&b=='B') return true;
	if(a=='B'&&b=='C') return true;
	if(a=='D'&&b=='F') return true;
	return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		d1=(s1[0]-'0')*10+s1[1]-'0';
		d2=(s2[0]-'0')*10+s2[1]-'0';
		if(d1==d2){
			cout<<1;
			if(pan()){
				cout<<1;
				if(pan2(s1[2],s2[2])) cout<<1;
				else cout<<0; 
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
