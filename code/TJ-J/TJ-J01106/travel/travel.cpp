#include<bits/stdc++.h>
using namespace std;
int a1,b1;
string a2,b2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//1 同车厢	2 同一排 3同一侧 4相邻 
	//保险 直接枚举所有可能 四条判断是递进关系 类似闯关，以此判断失败就直接结束 
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<"1";
	}
	else{
		cout<<"0000";//不是同一车厢全不满足
		return 0; 
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]){//?在同一排 
		if((a2[2]=='D'&&b2[2]=='E'||a2[2]=='E'&&b2[2]=='D')||(a2[2]=='A'&&b2[2]=='B'||a2[2]=='A'&&b2[2]=='C'||a2[2]=='B'&&b2[2]=='C'||a2[2]=='B'&&b2[2]=='A'||a2[2]=='C'&&b2[2]=='A'||a2[2]=='C'&&b2[2]=='B')){//同一侧 
			if((a2[2]=='A'&&b2[2]=='B'||a2[2]=='B'&&b2[2]=='C')||(a2[2]=='B'&&b2[2]=='A'||a2[2]=='C'&&b2[2]=='B')||(a2[2]=='D'&&b2[2]=='E'||a2[2]=='E'&&b2[2]=='D')){//相邻
				cout<<"111"; 
				return 0;
			}
			else{
				cout<<"110";
				return 0;
			}
		}
		else{
			cout<<"100";
			return 0;
		} 
	}
	else{
		cout<<"000";
		return 0;
	}
	return 0;
} 
