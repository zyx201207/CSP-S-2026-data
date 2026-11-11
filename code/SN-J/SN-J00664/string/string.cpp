//张皓禹 延安培文实验学校 SN-J00664 
#include<bits/stdc++.h>
using namespace std;

std::string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt;
	cin>>n;
	for(int i = 1;i <= n;i++){
	    int a;cin>>a;
		char c;cin>>c;
		for(int j = 0;j < a;j++){
			s[j] = c;
		}	
	}
	if(s.size() % 2 == 0){
		for(int i = s.size() - 1;i > s.size() / 2;i--){
			int j = 0;
			if(s[i] != s[j]) cnt++;
			j++;
		}
		cout<<cnt;
	}
	else{
		for(int i = s.size() - 1;i >= s.size() / 2;i--){
			int j = 0;
			if(s[i] != s[j]) cnt++;
			j++;
		}
		cout<<cnt;
	}
	return 0;
}
