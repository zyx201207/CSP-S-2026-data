#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define endl '\n'
int p1,p2;
char w1,w2;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>a1>>b1>>a2>>b2;
	p1=b1[0]+b1[1];
	p2=b2[0]+b2[1];
	w1=b1[2];
	w2=b2[2];
	if (a1==a2){
		cout<<"1";
		if (p1==p2){
			cout<<"1";
			if ((w1>='D'&&w2>='D')||(w1<='C'&&w2<='C')){
				cout<<"1";
				if ((w1=='A'&&w2=='C')||(w1=='C'&&w2=='A')){
					cout<<"0";
				}else{
					cout<<"1";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
