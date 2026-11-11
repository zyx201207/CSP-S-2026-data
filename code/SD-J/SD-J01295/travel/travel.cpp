#include"bits/stdc++.h"
using namespace std;

/*
模拟
期望得分：100pts 
*/
int n;
string c1,c2,s1,s2;
int jdz(int a){
	if(a<0)return -a;
	return a;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";	
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			int id1=s1[2]-'A',id2=s2[2]-'A';
			if(id1<3&&id2<3){
				cout<<"1";
				cout<<((jdz(id1-id2)==1)?"1":"0");
			}
			else if(id1>2&&id2>2){
				cout<<"1";
				cout<<((jdz(id1-id2)==1)?"1":"0");
			}
			else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
/*
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
02 02B 02 01A
02 01A 03 01A
08:35-08:55
-----------
csp-j
预估：100+100+52+65=317pts
已删除多余代码 
洛谷 uid 1795848 
*/
