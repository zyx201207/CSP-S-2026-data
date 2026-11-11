#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,a;
char q1='0',q2='0',q3='0',q4='0';
void question(){
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			return;
		}
	}
	q1='1';
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			return;
		}
	}
	q2='1';
	if(s1[2]<'D'&&s2[2]>'C'||s2[2]<'D'&&s1[2]>'C')return; 
	q3='1';
	if(s1[2]-'0'+1==s2[2]-'0'||s1[2]-'0'-1==s2[2]-'0')q4='1';
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	question();
	a.push_back(q1);
	a.push_back(q2);
	a.push_back(q3);
	a.push_back(q4);
	cout<<a;
	return 0;
}
