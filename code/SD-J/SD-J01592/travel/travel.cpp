#include <bits/stdc++.h>
using namespace std;



int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			int s31,s32;
			s31=s1[2];
			s32=s2[2];
			if(((!(s31=='D'||s31=='F'))&&(!(s32=='D'||s32=='F')))||((s31=='D'||s31=='F')&&(s32=='D'||s32=='F'))){
				cout<<1;
				if(((s31+1==s32)||(s31-1==s32))||((s31=='D'||s32=='F')||(s31=='F'||s32=='D'))) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
}

/*
	似乎很简单
	1.定义变量输入
	2.判断是否在一个车厢 
	
	好多判断 能否优化掉 
*/
