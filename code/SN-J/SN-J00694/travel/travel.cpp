//yanzhenni tongchuanshidisanzhongxue SN-J00694
#include <bits/stdc++.h>
using namespace std;
int main(){
	preopen("travel.in","r",stdin);
	preopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;//chexianghao zuoweihao
	if(c1==c2) cout<<"1";
	else cout<<"0";//tongyijiechexiang
	if(s1[0][1]==s2[0][1]) cout<<"1";
	else cout<<"0";//tongyipai
	if(si[2]==s2[2]) cout<<"1";
	else cout<<"0";//tongyice
	if(s1[2]+"32"==s2[2]) cout<<"1";
	else cout<<"0";//xianglin
	
	
	
	return 0;
}
