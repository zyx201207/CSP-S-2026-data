#include <bits/stdc++.h>
using namespace std;
struct s{
	int a;
	char c;
}str[200006];
string com2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>str[i].a >>str[i].c;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=str[i].a;j++){
			com2+=str[i].c;
		}
	}
	string yuanshi=com2;
	string com1;
	reverse(com2.begin(),com2.end());
	for(int i=0;i<=yuanshi.size()/2;i++){
		com1+=yuanshi[i]; 
	} 
	for(int i=yuanshi.size()/2-1;i>=0;i--){
		com1+=yuanshi[i];
	}
	int cnt1=0,cnt2=0;
	for(int i=0;i<=yuanshi.size();i++){
		if(com1[i]!=yuanshi[i]) cnt1++;
	}
	for(int i=0;i<=yuanshi.size();i++){
		if(com2[i]!=yuanshi[i]) cnt2++;
	}
	if(cnt1<cnt2){
		cout <<cnt1;
	}
	else{
		cout <<cnt2;
	}
	return 0;
}
