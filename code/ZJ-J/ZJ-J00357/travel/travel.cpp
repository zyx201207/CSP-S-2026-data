#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
inline bool check1(){return c1==c2;}
inline bool check2(){return s1.substr(0,2)==s2.substr(0,2);}
inline bool check3(){return (s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||((s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'));}
inline bool check4(){return abs(s1[2]-s2[2])==1;}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	cout<<check1()<<(check1()&&check2())<<(check1()&&check2()&&check3())<<(check1()&&check2()&&check3()&&check4());
	return 0;
}
/*
By ZJ-J00357.
Luogu UID:1086453.
*/