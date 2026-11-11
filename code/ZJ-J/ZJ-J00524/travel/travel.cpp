#include<bits/stdc++.h>
using namespace std;
bool flag1,flag2,flag3,flag4;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	freopen("travel5.in","r",stdin);
//	freopen("travel5.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>s1>>s2>>s3>>s4;
	string len1=s2.substr(0,2);
	string len2=s4.substr(0,2);
	char seat_1=s2[2];
	char seat_2=s4[2];
	if(s1==s3)flag1=true;
	if(flag1&&len1==len2)flag2=true;
	if(flag2){
		if((seat_1<='C'&&seat_2<='C')||(seat_1>='D'&&seat_2>='D'))flag3=true;
	}
	if(flag3&&abs(seat_1-seat_2)==1)flag4=true;
	cout<<flag1<<flag2<<flag3<<flag4<<"\n";
	return 0;
}