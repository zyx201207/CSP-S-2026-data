#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sb=0;
	cin >> n;
	string str,rts;
	while(n--){
		int a;
		cin >> a;
		string str2;
		cin >> str2;
		for(int i=0;i<a;i++){
			str+=str2;
		}
	}
	for(int i=str.size()-1;i>=0;i--){
		rts+=str[i];
	}
	if(str!=rts){
		for(int i=0;i<str.size();i++){
			if(str[i]!=rts[i]){
				sb++;
			}
		}
		cout << sb/2;
	}else{
		cout << 0;
	}
	return 0;
} 
