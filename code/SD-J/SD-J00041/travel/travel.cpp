#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+7;
string a,b,c,d;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a!=c){
		cout << "0000\n";
		return 0;
	}
	if(b[0]!=d[0] || b[1]!=d[1]){
		cout << "1000\n";
		return 0;
	}
	int u = b[2]-'A',v = d[2]-'A';
	if(u>v)swap(u,v);
	if((u==0 && v==1) || (u==1 && v==2) || (u==3 || v==5)){
		cout << "1111\n";
		return 0;
	}
	if(u==0 && v==2){
		cout << "1110\n";
		return 0;
	}
	cout << "1100\n";
	return 0;
}

