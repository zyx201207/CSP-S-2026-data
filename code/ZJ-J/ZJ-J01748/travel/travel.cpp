#include <bits/stdc++.h>
using namespace std;
long long r,x,rj[10],xj[10];
string rs,xs;
int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>r>>rs>>x>>xs;
	for (int i=0;i<=1;i++){
		rj[i+1]=rs[i]-48;
		xj[i+1]=xs[i]-48;
	}
	if (r!=x){
		cout<<"0000";
		return 0;
	}
	else if (r==x){
		cout<<'1';
		for (int i=1;i<=2;i++){
			if (rj[i]!=xj[i]){
				cout<<"000";
				return 0;
			}
		}
		cout<<'1';
		if (rs[2]=='D'||rs[2]=='F'){
			if (xs[2]=='D'||xs[2]=='F'){
				cout<<"11";
				return 0;
			}
			else if (xs[2]=='A'||xs[2]=='B'||xs[2]=='C'){
				cout<<"00";
				return 0;
			}
		}
		else if (rs[2]=='A'||rs[2]=='B'||rs[2]=='C'){
			if (xs[2]=='D'||xs[2]=='F'){
				cout<<"00";
				return 0;
			}
			else if (xs[2]=='A'||xs[2]=='B'||xs[2]=='C'){
				cout<<'1';
				if (rs[2]=='A'&&xs[2]=='B'){
					cout<<'1';
					return 0;
				}
				if (rs[2]=='A'&&xs[2]=='C'){
					cout<<'0';
					return 0;
				}
				if (rs[2]=='B'&&xs[2]=='A'){
					cout<<'1';
					return 0;
				}
				if (rs[2]=='B'&&xs[2]=='C'){
					cout<<'1';
					return 0;
				}
				if (rs[2]=='C'&&xs[2]=='A'){
					cout<<'0';
					return 0;
				}
				if (rs[2]=='C'&&xs[2]=='B'){
					cout<<'1';
					return 0;
				}
			}
		}
	}
	return 0;
}
