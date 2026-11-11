#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
	cin >> c1 >> c2 >> s1 >> s2;
	if (c1!=s1){
		cout << "0000";
		return 0;
	}
	if (c1==s1){
		cout << "1";
	}
	char a1=c2[0];
	char a2=c2[1];
	char a3=c2[2];
	char b1=s2[0];
	char b2=s2[1];
	char b3=s2[2];
	int q=a1-'0';
	int q1=a2-'0';
	int num1=q*10+q1;
	int p=b1-'0';
	int p1=b2-'0';
	int num2=p*10+p1;
	if (num1!=num2){
		cout << "000";
		return 0;
	}
	else{
		cout << "1";
	}
	if ((a3=='A' || a3=='B' || a3=='C') &&  (b3=='D' || b3=='F')){
		cout << "00";
		return 0;
	}
	else if((b3=='A' || b3=='B' || b3=='C') &&  (a3=='D' || a3=='F')){
		cout << "00";
		return 0;
	}
	else {
		cout << "1";
	}
	if (a3=='A' && b3=='B') cout << "1";
	else if(a3=='B' && (b3=='A' || b3=='C')) cout << "1";
	else if(a3=='C' && b3=='B') cout << "1";
	else if(a3=='D' && b3=='F') cout << "1";
	else if(a3=='F' && b3=='D') cout << "1";
	else {
		cout << "0";
	} 
	return 0;
}

