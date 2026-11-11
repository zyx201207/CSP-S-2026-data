#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1, s1, c2, s2;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;char a=s1[2], b=s2[2];
			bool aa=(a<='C'), bb=(b<='C');
			if(aa==bb){
				cout<<1;
				if(a>b)swap(a, b);
				cout<<((b-a)==1||a=='D');
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

