#include<bits/stdc++.h>
using namespace std;
bool nextto(int a,int b){
	if((a==1&&b==2)||(a==2&&b==1)||(a==2&&b==3)||(a==3&&b==2)||(a==4&&b==6)||(a==6&&b==4)){
		return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	int c1,c2,s1,s2;
	int seat1,seat2;
	cin>>s;
	c1=(int(s[0])-'0')*10+(int(s[1])-'0');
	cin>>s;
	s1=(int(s[0])-'0')*10+(int(s[1])-'0');
	seat1=int(s[2])-'A'+1;
	cin>>s;
	c2=(int(s[0])-'0')*10+(int(s[1])-'0');
	cin>>s;
	s2=(int(s[0])-'0')*10+(int(s[1])-'0');
	seat2=int(s[2])-'A'+1;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c1==c2&&s1==s2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c1==c2&&s1==s2&&((seat1>=4&&seat2>=4)||(seat1<=3&&seat2<=3))){
		cout<<"1";
	} 
	else{
		cout<<"0";
	}
	if(c1==c2&&s1==s2&&nextto(seat1,seat2)){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
} 
