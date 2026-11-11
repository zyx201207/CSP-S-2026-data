#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2,sss1,sss2;
char ss1,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> c1 >> s1 >> ss1 >> c2 >> s2 >> ss2;//2 1 A 2 1 B
	if(ss1=='A'){
		sss1=101;
	}else if(ss1=='B'){
		sss1=102;
	}else if(ss1=='C'){
		sss1=103;
	}else if(ss1=='D'){
		sss1=10001;
	}else{
		sss1=10002;
	}
	if(ss2=='A'){
		sss2=101;
	}else if(ss2=='B'){
		sss2=102;
	}else if(ss2=='C'){
		sss2=103;
	}else if(ss2=='D'){
		sss2=10001;
	}else{
		sss2=10002;
	}
	if(c1!=c2){
		cout << "0000";
		return 0; 
	}else{
		cout << "1";
	}
	if(s1!=s2){
		cout << "000";
		return 0;
	}else{
		cout << "1";
	}
	if(sss1+sss2>=10102&&sss1+sss2<=10105){
		cout <<"00";
		return 0;
	}else{
		cout << "1";
	}
	if(abs(sss2-sss1)!=1){
		cout << "0";
		return 0;
	}else{
		cout << "1";
	}
	return 0;
}

