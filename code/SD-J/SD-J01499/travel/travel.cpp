#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
char f1[6]={'A','B','C'};
char f2[6]={'D','F'}; 
bool check1(char x,char y){
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++){
			if(x==f1[i]&&y==f2[j]){
				return 0;
			}
		}
	}
	return 1;
}
bool check(char x,char y){
	if((x=='A'&&y=='B')||(x=='B'&&y=='C')||(y=='A'&&x=='B')||(y=='B'&&x=='C')||(x=='D'&&y=='F')||(x=='F'&&y=='D')){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	s1="#"+s1;
	s2="#"+s2;
	if(c1==c2){
		ans+='1';
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
//			cout<<"21\n";
			ans+='1';
			if(check1(s1[3],s2[3])){
				ans+='1';
				if(check(s1[3],s2[3])){
					ans+='1';
				}
				else{
					ans+='0';
				}
			}
			else{
				ans+="00";
			}
		}
		else{
			ans+="000";
		}
	}
	else{
		ans="0000";
	}
	cout<<ans;
	return 0;
} 
