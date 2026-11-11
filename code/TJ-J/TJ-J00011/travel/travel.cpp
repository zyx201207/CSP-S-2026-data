#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ans1,ans2,ans3,ans4;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		ans1="1";
		cout<<ans1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans2="1";
			cout<<ans2;
			if((s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F')||(s1[2]=='C'&&s1[2]=='B'||s1[2]=='A'&&s2[2]=='C'||s2[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'||s1[2]=='A'&&s2[2]=='B')){
				ans3="1";
				cout<<ans3;
				if(s1[2]=='A'&&s2[2]=='C'||s2[2]=='A'&&s1[2]=='C'){
					ans4="0";
					cout<<ans4;
				}
				else{
					ans4="1";
					cout<<ans4;
				}
			}
			else{
				ans3="0";
				cout<<ans3;
				ans4="0";
				cout<<ans4;
			}
		}
		else{
			ans2="0";
			cout<<ans2;
			ans3="0";
			cout<<ans3;
			ans4="0";
			cout<<ans4;
		}
	}
	else{
		ans1="0";
		cout<<ans1;
		ans2="0";
		cout<<ans2;
		ans3="0";
		cout<<ans3;
		ans4="0";
		cout<<ans4;
	}
	return 0;
}
