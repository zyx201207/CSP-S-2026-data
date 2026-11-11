#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout << 1;
		int len1=s1.size();
		int len2=s2.size();
		int sum1,sum2;
		if(len1==3){
			sum1=(s1[0]-'0')*10+(s1[1]-'0');
		}else{
			sum1=s1[0]-'0';
		}
		if(len2==3){
			sum2=(s2[0]-'0')*10+(s2[1]-'0');
		}else{
			sum2=s2[0]-'0';
		}
		if(sum1==sum2){
			cout << 1;
			char st1,st2;
			if(len1==3){
				st1=s1[2];
			}else{
				st1=s1[1];
			}
			if(len2==3){
				st2=s2[2];
			}else{
				st2=s2[1];
			}
			if((st1=='A'&&st2=='B')||(st2=='A'&&st1=='B')||(st2=='C'&&st1=='B')||(st2=='B'&&st1=='C')||(st2=='A'&&st1=='C')||(st2=='C'&&st1=='A')||(st2=='D'&&st1=='F')||(st2=='F'&&st1=='D')){
				cout << 1;
				if((st1=='A'&&st2=='B')||(st2=='A'&&st1=='B')||(st2=='C'&&st1=='B')||(st2=='B'&&st1=='C')||(st2=='D'&&st1=='F')||(st2=='F'&&st1=='D')){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
