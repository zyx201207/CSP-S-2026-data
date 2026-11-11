#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool p;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	int l1 = s1[0]-'0'*10+s1[1]-'0';
	int l2 = s2[0]-'0'*10+s2[1]-'0';
	if(l1==l2){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	int m1 = s1[2]-'A'+1;
	int m2 = s2[2]-'A'+1;
	if(m1<=3&&m2<=3||m1>=4&&m2>=4){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(m1<=3&&m2<=3&&abs(m1-m2)==1||m1>=4&&m2>=4){
		cout<<1;
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
