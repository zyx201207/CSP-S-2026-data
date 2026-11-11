#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("string.in");
	ofstream fout("string.out");
	int n,cnt=0;
	string s=" ";
	fin>>n;
	while(n--){
		long long m;
		char c;
		fin>>m>>c;
		s.append(m,c);
	}
	s=s.substr(1,s.size());     
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			cnt++;
		}
	}
	fout<<cnt;
	return 0;
}