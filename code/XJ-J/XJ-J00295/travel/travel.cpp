#include<bits/stdc++.h>
using namespace std;
string a[10]= {"A","B","C","X","D","F"};
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,x,n,y;
	cin>>s;
	cin>>x;
	cin>>n;
	cin>>y;
	string a1=x.substr(0,2);
	string b1=x.substr(2,3);
	string a2=y.substr(0,2);
	string b2=y.substr(2,3);
	int q=0,w=0,e=0,r=0;
	if(s==n) {
		q=1;
		
	}else{
		cout<<q<<w<<e<<r;
		return 0;
	}
	if(a1==a2) {
		w=1;
		bool f=false,l=false;
		if(b1>="D") {
			f=true;
		}
		if(b2>="D") {
			l=true;
		}
		if(f==l) {
			e=1;
		}
		for(int i=0; i<5; i++) {
			if(b1==a[i]) {
				if(b2==a[i+1]||b2==a[i-1]) {
					r=1;
					cout<<q<<w<<e<<r;
					return 0;
				}
			}
		}
	}
	cout<<q<<w<<e<<r;
	return 0;
}
