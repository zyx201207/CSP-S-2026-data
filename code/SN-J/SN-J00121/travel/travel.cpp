#include <bits/stdc++.h>
using namespace std;

int main(){ 
	freopen("in.travel","r",stdin);
	freopen("out.travel","w",stdout);
	
	string c1;
	string s1;
	string c2;
	string s2;

	//cin >> c1 >> s1 >> c2 >> s2;
	for(int i = 1; i <= 2; i ++){
		cin >> c1[i];
	}
	for(int i = 1; i <= 3; i ++){
		cin >> s1[i];
	}
	for(int i = 1; i <= 2; i ++){
		cin >> c2[i];
	}
	for(int i = 1; i <= 3; i ++){
		cin >> s2[i];
	}
	
	if(c1 == c2){
		cout << 1;
	}else{
		cout << 0;
	}
	if(s1[0] == s2[0] && s2[2] == s1[2] && c1 == c2){
		cout << 1;
	}else{
		cout << 0;
	}
	if(s1[3] == 'A' && s2[3] == 'B' && c1 == c2){
		cout << 1;
	}else if(s1[3] == 'A' && s2[3] == 'C' && s1[1] == s2[1] && s2[2] == s1[2] && c1 == c2){
		cout << 1;
	}else if(s1[3] == 'A' && s2[3] == 'B' && s1[1] == s2[1] && s2[2] == s1[2] && c1 == c2){
		cout << 1;
	}else if(s1[3] == 'A' && s2[3] == 'A' && s1[1] == s2[1] && s2[2] == s1[2] && c1 == c2){
		cout << 1;
	}else if(s1[3] == 'B' && s2[3] == 'A' && s1[1] == s2[1] && s2[2] == s1[2] && c1 == c2){
		cout << 1;
	}else if(s1[3] == 'B' && s2[3] == 'B' && s1[1] == s2[1] && s2[2] == s1[2] && c1 == c2){
		cout << 1;
	}else if(s1[3] == 'B' && s2[3] == 'C' && s1[1] == s2[1] && s2[2] == s1[2] && c1 == c2){
		cout << 1;
	}else if(s1[3] == 'C' && s2[3] == 'B' && s1[1] == s2[1] && s2[2] == s1[2] && c1 == c2){
		cout << 1;
	}else if(s1[3] == 'C' || s2[3] == 'C' && s1[1] == s2[1] && s2[2] == s1[2] && c1 == c2){
		cout << 1;
	}else if(s1[3] == 'D' && s2[3] == 'F'&& s1[1] == s2[1] && s2[2] == s1[2] && c1 == c2){
		cout << 1;
	}else if(s1[3] == 'F' && s2[3] == 'D' && s1[1] == s2[1] && s2[2] == s1[2] && c1 == c2){
		cout << 1;
	}else if(s1[3] == 'D' && s2[3] == 'D' && s1[1] == s2[1] && s2[2] == s1[2] && c1 == c2){
		cout << 1;
	}else if(s1[3] == 'F' && s2[3] == 'F' && s1[1] == s2[1] && s2[2] == s1[2] && c1 == c2){
		cout << 1;
	}else{
		cout << 0;
	}
	
	if(s1[3] == 'A' && s2[3] == 'B' && s1[1] == s2[1] && s2[2] == s1[2]){
		cout << 1;
	}else if(s1[3] == 'B' && s2[3] == 'A' && s1[1] == s2[1] && s2[2] == s1[2]){
		cout << 1;
	}else if(s1[3] == 'B' && s2[3] == 'C' && s1[1] == s2[1] && s2[2] == s1[2]){
		cout << 1;
	}else if(s1[3] == 'C' && s2[3] == 'B' && s1[1] == s2[1] && s2[2] == s1[2]){
		cout << 1;
	}else if(s1[3] == 'D' && s2[3] == 'F' && s1[1] == s2[1] && s2[2] == s1[2]){
		cout << 1;
	}else if(s1[3] == 'F' && s2[3] == 'D' && s1[1] == s2[1] && s2[2] == s1[2]){
		cout << 1;
	}else{
		cout << 0;
	}
	//我去shi山能过，太不可思议了！ 这辈子能开心死我 
	
	 
	
	
	
	return 0;
}
