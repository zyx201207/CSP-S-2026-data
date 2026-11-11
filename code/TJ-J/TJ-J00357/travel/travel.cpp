#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}if(s1[0]==s2[0]&&s1[1]==s2[1]){
		int t=((s1[2]>=65&&s1[2]<=67)&&(s2[2]>=65&&s2[2]<=67));
		int t2=((s1[2]>=68&&s1[2]<=69)&&(s2[2]>=68&&s2[2]<=69));
		if((t)){
			int k=(s1[2]=='A'&&s2[2]=='B');
			int k2=(s1[2]=='B'&&s2[2]=='A');
			int k3=(s1[2]=='C'&&s2[2]=='B');
			int k4=(s1[2]=='B'&&s2[2]=='C');
			if(k||k2||k3||k4){
				cout<<"1111";
				return 0;
			}else{
				cout<<"1110";
			}
		}else if(t2){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1100";
		}
	}else{
		cout<<"1000";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
