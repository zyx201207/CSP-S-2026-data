#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool pd(int x,int y){
	if(x==1&&y==2) return 1;
	if(x==2&&y==3) return 1;
	if(x==4&&y==6) return 1;
	if(x==2&&y==1) return 1;
	if(x==3&&y==2) return 1;
	if(x==6&&y==4) return 1;
	return 0;
}
bool pd1(int x,int y){
	if(x>=1&&x<=3&&y>=1&&y<=3) return 1;
	if(x>=4&&x<=6&&y>=4&&y<=6) return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int s3=((s1[0]-'0')*10+(s1[1]-'0'));
	int s4=s1[2]-'A'+1;
	int s5=((s2[0]-'0')*10+(s2[1]-'0'));
	int s6=s2[2]-'A'+1;
	if(c1==c2) cout<<'1'; else cout<<'0';
	if(c1==c2&&s3==s5) cout<<'1'; else cout<<'0';
	if(c1==c2&&s3==s5&&pd1(s4,s6)) cout<<'1'; else cout<<'0';
	if(c1==c2&&s3==s5&&pd(s4,s6)&&pd1(s4,s6)) cout<<'1'; else cout<<'0';
	return 0;
}
