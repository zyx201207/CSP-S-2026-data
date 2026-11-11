#include<bits/stdc++.h>
using namespace std;

string cut(string s,int len){
	string ans = "";
	int now = 0;
	for(char i : s){
		if(now == len) break;
		++now;
		ans.push_back(i);
	}
	
	return ans;
}

int side(char a, char b){
	
	if(a == 'F' || a == 'D'){
		if(b == 'F' || b == 'D') return 1;
	}
	if(a == 'A' || a == 'B' || a == 'C'){
		if(b == 'A' || b == 'B' || b == 'C') return 2;
	}
	
	return 0;
}

void func(vector<vector<string> > &v){
	
	if(v[0][0] == v[1][0]){
		cout<<1;
	}
	else{
		cout<<"0000\n";
		return;
	}
	
	string s1,s2;
	s1 = cut(v[0][1],2);
	s2 = cut(v[1][1],2);
	if(s1 == s2){
		cout<<1;
	}
	else{
		cout<<"000\n";
		return;
	}
	
	char c1,c2;
	c1 = v[0][1].back();
	c2 = v[1][1].back();
	int t = side(c1, c2);
	if(t==0){  //²»ÔÚ 
		cout<<"00\n";
		return;
	}
	else if(t==1){  //DF 
		cout<<"11\n";
		return;
	}
	else{  //ABC
		cout<<1;
	}
	
	if(c1 == 'B' || c2 == 'B'){
		cout<<"1\n";
	}
	else{
		cout<<"0\n";
	}
	
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	vector<vector<string> > v(2,vector<string>(2));
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cin>>v[i][j];
		}
	}
	
	func(v);
	
	return 0;
}
