#include<iostream>
using namespace std;
string c1s,s1s,c2s,s2s;
int c1,c2,p1,p2,w1,w2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1s>>s1s>>c2s>>s2s;
	c1=(c1s[0]-'0')*10+c1s[1]-'0';
	c2=(c2s[0]-'0')*10+c2s[1]-'0';
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	p1=(s1s[0]-'0')*10+s1s[1]-'0';
	p2=(s2s[0]-'0')*10+s2s[1]-'0';
	if(p1!=p2){
		cout<<"1000";
		return 0;
	}
	w1=s1s[2]-'A'+1;
	w2=s2s[2]-'A'+1;
	if(w1>=4&&w2>=4){
		cout<<"1111";
		return 0;
	}
	if(w1<=3&&w2>=4||w1>=4&&w2<=3){
		cout<<"1100";
		return 0;
	}
	if(w1+1==w2||w1-1==w2){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}
