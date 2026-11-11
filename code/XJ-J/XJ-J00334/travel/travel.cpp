#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
char s[]={'A','B','C','D','F'};
bool check2(int x) {
	if(s[x]=='A') {
		if(x2[2]=='B') return true;
	}
	if(s[x]=='B') {
		if(x2[2]=='A'||x2[2]=='C') return true;
	}
	if(s[x]=='C') {
		if(x2[2]=='B') return true;
	}
	if(s[x]=='D') {
		if(x2[2]=='F') return true;
	}
	if(s[x]=='F') {
		if(x2[2]=='D') return true;
	}
	return false; 
}
bool check1() {
	if(r2[2]=='A'||r2[2]=='B'||r2[2]=='C') {
		if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C') return true;
		else return false;
	}
	if(r2[2]=='D'||r2[2]=='F') {
		if(x2[2]=='D'||x2[2]=='F') return true;
		else return false;
	}
}
void solve() {
	bool f=true;
	for(int i=0;i<2;i++) {if(r1[i]!=x1[i]) f=false;}
	if(!f) cout<<"0000";
	else {
		cout<<"1";
		f=true;
		for(int i=0;i<2;i++) {
			if(r2[i]!=x2[i]) f=false;
		}
		if(!f) cout<<"000";
		else {
			cout<<"1";
			if(check1()) cout<<"1";
			else cout<<"0";
			for(int i=0;i<5;i++) {
				if(r2[2]==s[i]) {
					if(check2(i)) cout<<"1";
					else cout<<"0";
				}
			}
		}
	}
}
int main() {
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>r1>>r2>>x1>>x2;
	solve();
	return 0;
} 
