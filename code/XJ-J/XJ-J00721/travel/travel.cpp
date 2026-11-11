# include<bits/stdc++.h>
using namespace std;
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,cnt;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cnt+='1';
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cnt+='1';
			if(abs((int)s1[2]-(int)s2[2])<=2 || abs((int)s1[2]-(int)s2[2])==1){
					if((s1[2]=='C' && s2[2]=='D') || (s2[2]=='C' && s1[2]=='D')){
						cnt+="00";
						cout<<cnt;
						return 0 ;
					}
					cnt+='1';
					if(abs((int)s1[2]-(int)s2[2])==1){
					cnt+='1';
					cout<<cnt;
				}
				else {
					cnt+='0';
					cout<<cnt;
				}
			}
			else {
				cnt+="00";
				cout<<cnt;
			}
		}
		else {
			cnt+="000";
			cout<<cnt;
		}
	}
	else {
		cnt="0000";
		cout<<cnt;
	}
	return 0 ;
}