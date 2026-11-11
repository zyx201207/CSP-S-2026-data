//姓名：霍梓颐 考号：SN-J00766 学校：西北大学附属中学 
#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int l1=s1[0]*10+s1[1];
	int l2=s2[0]*10+s2[1];
	int g1=s1[2],g2=s2[2];
	if(c1!=c2) cout<<"0000";
	else{
		if(l1!=l2) cout<<"1000";
		else{
			if(g1>='A'&&g1<='C'&&g2>='A'&&g2<='C'){
				if(abs(int(g1-g2))==1) cout<<"1111";
				else cout<<"1110"; 
			}else if((g1=='D'||g1=='F')&&(g2=='D'||g2=='F')){
				cout<<"1111";
			}else cout<<"1100";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
