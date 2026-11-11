#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	long long sp1,sp2;
	sp1=(s1[0]-'0')*10+(s1[1]-'0');
	sp2=(s2[0]-'0')*10+(s2[1]-'0');
	long long ss1,ss2;
	ss1=s1[2]-'0',ss2=s2[2]-'0';
	if(c1==c2){
		cout<<"1";
		if(sp1==sp2){
			cout<<"1";
			if(((ss1==17 or ss1==18 or ss1==19) and (ss2==17 or ss2==18 or ss2==19)) or ((ss1==20 or ss1==22) and (ss2==20 or ss2==22))){
				cout<<"1";
				if(ss1+1==ss2 or ss1-1==ss2 or (ss1==20 and ss2==22) or (ss1==22 and ss2==20)){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
					
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
	return 0;
}
