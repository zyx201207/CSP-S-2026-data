#include<bits/stdc++.h>
using namespace std;
long long cx1,p1,c1_,cx2,p2,c2_;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cx1=(c1[0]-'0')*10+(c1[1]-'0');
	cx2=(c2[0]-'0')*10+(c2[1]-'0');
	if(cx1==cx2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	p1=(s1[0]-'0')*10+(s1[1]-'0');
	p2=(s2[0]-'0')*10+(s2[1]-'0');
	if(p1==p2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	c1_=s1[2]-'A'+1;
	c2_=s2[2]-'A'+1;
	if(c1_<=3&&c2_<=3){
		cout<<1;
	}
	else if(c1_>=4&&c2_>=4){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(c1_-c2_==1||c2_-c1_==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
