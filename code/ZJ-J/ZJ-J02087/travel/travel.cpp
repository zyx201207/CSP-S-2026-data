#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;int m,n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a!=b){cout<<"0000";return 0;}
	m=x[0]*10+x[1],n=y[0]*10+y[1];
	if(m!=n){cout<<"1000";return 0;}
	char c=x[2],d=y[2];
	if(c>d)swap(c,d);
	if((c=='A'&&d=='D')||(c=='A'&&d=='F')||(c=='B'&&d=='D')||(c=='B'&&d=='F')||(c=='C'&&d=='D')||(c=='C'&&d=='F')){
		cout<<"1100";return 0;
	}
	if(c=='A'&&d=='C'){
		cout<<"1110";return 0;
	}
	cout<<"1111";
	return 0;
}

