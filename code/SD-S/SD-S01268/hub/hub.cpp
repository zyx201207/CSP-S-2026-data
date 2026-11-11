#include <iostream>
#include <vector>
using namespace std;
string str1;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	string str1,s[100]={
	"(If you do not open this file,you can't find this)",
	"Hi,This is a...",
	"?",
	"What are you doing?",
	"OK,But the exam...",
	"Can you help me?",
	"To AK--CSP-J/S AND-- IOI!!!",
	"What?You are a OIer? ",
	"Q",
	"Are you a Oler?(N/N)",
	"NOOOOO"
	};
	for(int i = 1;i <= 10;i++){
		cout << s[i];
		if(s[i] == "Q"){
			cout << "uestion:" << s[i+1];
			cin >> str1;
			i++;
		}
		cout << '\n';
	}
	short RP;
	RP++;
	return 0;
}
