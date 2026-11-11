#include<bits/stdc++.h>
using namespace std;
long long a,b,d,e;
char c,f;
bool t1,t2,t3,t4;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	for(int i=1;i<=2;i++){
		cin>>c;
		d=d*10+c-'0';
	}cin>>c;
	cin>>b;
	for(int i=1;i<=2;i++){
		cin>>f;
		e=e*10+f-'0';
	}cin>>f;
//	cout<<c<<' '<<f<<' ';
	if(a==b){
		t1=1;
		if(d==e){
			t2=1;
			if((c=='A'||c=='B'||c=='C')&&(f=='A'||f=='B'||f=='C')){
				t3=1;
				if((c=='A'&&f=='B')||(c=='B'&&f=='A')||(c=='B'&&f=='C')||(c=='C'&&f=='B')){
					t4=1;
//					cout<<(c=='A'&&f=='B')<<(c=='B'&&f=='A')<<(c=='B'&&f=='C')<<(c=='C'&&f=='B');
				}
			}else if((c=='D'||c=='F')&&(f=='D'||f=='F')){
				t3=t4=1;
			}
		}
	}cout<<t1<<t2<<t3<<t4;
	return 0; 
}
