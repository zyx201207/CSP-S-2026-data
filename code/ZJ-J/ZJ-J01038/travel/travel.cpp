#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
int num1,num2,num3,num4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++) num1=num1*10+c1[i]-'0';
	for(int j=0;j<c2.size();j++) num2=num2*10+c2[j]-'0';
	if(num1==num2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s1.size()-1;i++) num3=num3*10+s1[i]-'0';
	for(int j=0;j<s2.size()-1;j++) num4=num4*10+s2[j]-'0';
	if(num3==num4) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char ch1=s1[s1.size()-1],ch2=s2[s2.size()-1];
	int w1,w2;
	if(ch1=='A') w1=1;
	else if(ch1=='B') w1=2;
	else if(ch1=='C') w1=3;
	else if(ch1=='D') w1=4;
	else if(ch1=='F') w1=5;
	if(ch2=='A') w2=1;
	else if(ch2=='B') w2=2;
	else if(ch2=='C') w2=3;
	else if(ch2=='D') w2=4;
	else if(ch2=='F') w2=5;
	if(w1<=3 && w2<=3) cout<<1;
	else if(w1>=4 && w2>=4) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(w1-w2)<=1) cout<<1;
	else cout<<0;
	return 0;
}