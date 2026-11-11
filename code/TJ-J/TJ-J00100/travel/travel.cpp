#include<bits/stdc++.h>
using namespace std;
int a1,a2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2)cout<<1;
	else cout<<0;
	bool flag1=true;
	if(s1.size()==s2.size()){
		for(int i=0;i<s1.size()-1;i++){
			if(s1[i]!=s2[i]){
				flag1=false;
				break;
			}
		}
	}
	else flag1=false;
	if(a1==a2&&flag1)cout<<1;
	else cout<<0;
	bool flag2=false;
	int k1=s1.size()-1;
	int k2=s2.size()-1;
	if(s1[k1]=='A'&&s2[k2]=='B')flag2=true;
	if(s1[k1]=='A'&&s2[k2]=='C')flag2=true;
	if(s1[k1]=='B'&&s2[k2]=='C')flag2=true;
	if(s1[k1]=='B'&&s2[k2]=='A')flag2=true;
	if(s1[k1]=='C'&&s2[k2]=='A')flag2=true;
	if(s1[k1]=='C'&&s2[k2]=='B')flag2=true;
	if(s1[k1]=='F'&&s2[k2]=='D')flag2=true;
	if(s1[k1]=='D'&&s2[k2]=='F')flag2=true;
	bool flag3=false;
	if((a1/19==a2/19)&&s1[0]==s2[0]&&flag1&&flag2)cout<<1;
	else cout<<0;
	if(abs(int(s1[k1]-s2[k2]))==1)flag3=true;
	if((a1/19==a2/19)&&s1[0]==s2[0]&&flag1&&flag2&&flag3)cout<<1;
	else cout<<0;
	return 0;
}
