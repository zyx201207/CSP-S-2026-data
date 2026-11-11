//travel
//RP++
#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
const int N=5;
ll flag[N];

ll calc(string st){
	ll num=0;
	for(int i=0;i<=1;i++){
		num=num*10+st[i]-'0';
	}
	return num;
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	
	//判断否在同一车厢
	if(c1==c2) flag[1]=1;
	//判断是否在同一节车厢的同一排
	ll line1=calc(s1);
	ll line2=calc(s2);
	if(flag[1] && line1==line2) flag[2]=1;
	//判断是否在同一节车厢的同一排，且位于过道的同一侧
	if(flag[2] && ((s1[2]>='A' && s2[2]<='C') || (s1[2]>='D' && s2[2]<='E'))) flag[3]=1;
	//判断座位是否相邻
	if(flag[3] && abs(s1[2]-s2[2])==1) flag[4]=1;
	
	for(int i=1;i<=4;i++) cout<<flag[i];
	return 0; 
}
