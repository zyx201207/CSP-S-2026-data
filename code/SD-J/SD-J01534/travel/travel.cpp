#include<bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2;
int flag1,flag2,flag3,flag4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		flag1=1;
	}
	string p1=s1.substr(0,2);
	string p2=s2.substr(0,2);
	if(flag1 && p1==p2) flag2=1;
	if(flag2 && ((s1[2]>='D' && s2[2]>='D') || (s1[2]<'D' && s2[2]<'D'))){
		flag3=1;
	}
	char a=s1[2];
	char b=s2[2];
	if(flag3 && abs(a-b)<=1) flag4=1;
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
} 
