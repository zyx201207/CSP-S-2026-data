//SN-J00797 霍彧昂 西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
int n,a,num;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a >> c;
		for(int j = i; j <= n; j++) s += c;
	}
	
	int x = 0,y = s.size()-1;
	char l = s[x];
	char r = s[y];
	while(x <= y){
		if(l != r) num++;
		x++;
		y--;
		l = s[x];
		r = s[y];
	}
	
	cout << num;
	return 0;
}
