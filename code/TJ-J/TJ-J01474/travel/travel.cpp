#include <bits/stdc++.h> 
using namespace std;

string c1,c2,s1,s2;//c³µÏá,s×ùÎ» 

int getc(string s){
	return (s[0]-'0')*10 + (s[1]-'0');
}

bool sames(string x, string y){
	if( ( (x[2] == 'A' || x[2] == 'B' || x[2] == 'C') && (y[2] == 'A' || y[2] == 'B' || y[2] == 'C') )
	 || ( (x[2] == 'D' || x[2] == 'F') && (y[2] == 'D' || y[2] == 'F') ) ) return true;
	else return false;
}

string ans[4] = {"AB","BC","DF"};

bool nextt(string x, string y){
	string z = "";
	z += x[2];
	z += y[2];
	for(int i = 0; i < 3; i++){
		if(z == ans[i]) return true;
	}
	return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	//1
	if(c1 == c2) cout << "1";
	else cout << "0";
	//2
	int p1 = getc(s1);
	int p2 = getc(s2);
	if(c1 == c2 && p1 == p2) cout << "1";
	else cout << "0";
	//3
	if(c1 == c2 && p1 == p2 && sames(s1,s2)) cout << "1";
	else cout << "0";
	//4
	if(c1 == c2 && p1 == p2 && sames(s1,s2) && nextt(s1,s2)) cout << "1";
	else cout << "0";
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
