#include<bits/stdc++.h>
using namespace std;
int n,m,top;
int stk[200005];
string two[200005];
string to_two(int a){
	string ans;
	while (a){
		ans = to_string(a%2)+ans;
		a/=2;
	}
	while (ans.size()<30)ans = "0"+ans;
	return ans;
}
int bit_weather(int bit){
	int cnt=0;
	for(int i=0; i<n; i++){
		cnt+=two[i][bit]-'0';
		if(two[i][bit]=='1')cout << "<choose" << i << '>';//
	}
	return cnt;
}
void choose(int bit){
	int cs;
	if(bit_weather(bit)>=m)cs=1;
	else return;
	for(int i=0; i<n; i++){
		if((two[i][bit]-'0')!=cs)two[i]="000000000000000000000000000000";
	}
	return;
}
void stkin(string s){
	int num=0;
	for ( int i=0; i<(int)s.size(); i++){
		num = num*2+(s[i]-'0');
	}
	stk[top+1]=num;
	top++;
	return;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		long long a;
		cin >> a;
		two[i] = to_two(a);
	}
	int bit=20;
	while(bit<30){
		for(int i=0; i<n; i++){//
			cout << two[i] << ' ';//
		}//
		cout << endl;//
		choose(bit);
		bit++;
	}
	top=-1;
	for(int i=0; i<n; i++){
		if(two[i]!="000000000000000000000000000000"){
			stkin(two[i]);
		}
	}
	int ans=stk[0];
	for(int i=0; i<=top; i++){
		ans &= stk[i];
		cout << stk[i] << ' ';
	}
	cout << ans;
}
