#include<bits/stdc++.h>
#define io ios::sync_with_stdio();cin.tie();cout.tie();
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	io;
	string c,s,C,S;
	cin>>c>>s>>C>>S;
	if(c==C){
		cout<<1;
		if(s[0]==S[0]&&s[1]==S[1]){
			cout<<1;
			if(s[2]=='D'){
				if(S[2]=='F') cout<<1<<1;
				else{
					cout<<0<<0;
				}
			}
			else if(s[2]=='F'){
				if(S[2]=='D') cout<<1<<1;
				else{
					cout<<0<<0;
				}
			} 
			else if(s[2]=='A'){
				if(S[2]=='B'||S[2]=='C'){
					cout<<1;
					if(S[2]=='B') cout<<1;
					else cout<<0;
				}
				else cout<<0<<0;
			}
			else if(s[2]=='B'){
				if(S[2]=='A'||S[2]=='C'){
					cout<<1<<1;
				}
				else cout<<0<<0;
			}
			else if(s[2]=='C'){
				if(S[2]=='B'||S[2]=='A'){
					cout<<1;
					if(S[2]=='B') cout<<1;
					else cout<<0;
				}
				else cout<<0<<0;
			}
		}
		else cout<<0<<0<<0;
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
//Trick||Treat!
//02 01A 02 01B
//9:00 调完
//11:03有感而发 
//有一个竞赛叫csp~~
//有一个年份是2026~~
//前两题水~水~水~~
//后两题坏~坏~坏~~
//如果CCF要搞破坏 ~~
//我们不能阻止它~~ 
//后面忘了
//11:53吓哭了少写了一种情况赶紧改正 
