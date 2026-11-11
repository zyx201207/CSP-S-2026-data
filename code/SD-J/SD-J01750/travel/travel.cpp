#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int a=0;
	int b=0;
	for(int i=0;i<s1.size();i++){
		a=a*10+s1[i]-'0';
	}
	for(int i=0;i<s3.size();i++){
		b=b*10+s3[i]-'0';
	}
	if(a==b){
		cout << "1";
		int c=0;
		int d=0;
		for(int i=0;i<s2.size();i++){
			if(s2[i]>='0'&&s2[i]<='9'){
				c=c*10+s2[i]-'0';
			}
		}
		for(int i=0;i<s4.size();i++){
			if(s4[i]>='0'&&s4[i]<='9'){
				d=d*10+s4[i]-'0';
			}
		}
		if(c==d){
			cout << "1";
			int ans=s2[s2.size()-1]-64;
			int cnt=s4[s4.size()-1]-64;
			if((ans<=3&&cnt<=3)||(ans>3&&cnt>3)){
				cout << "1";
				if(abs(ans-cnt)==1){
					cout << "1";
				}else{
					cout << "0";
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
