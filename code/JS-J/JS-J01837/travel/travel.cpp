#include<bits/stdc++.h>
#define ll long long
using namespace std;
int q[6]={0,0,0,1,-1,1};
int w[6]={0,1,2,5,99999,6};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;// c1,s1,c2,s2
    cin>>a>>b>>c>>d;
    if(a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(a==c){
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	
	if(a==c){
		if(b[0]==d[0]&&b[1]==d[1]){
			if(q[b[2]-'A']==q[d[2]-'A']){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	
	if(a==c){
		if(b[0]==d[0]&&b[1]==d[1]){
			if(q[b[2]-'A']==q[d[2]-'A']){
				if(abs((b[2]-'A')-(d[2]-'A'))==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}//CSP 2026 RP++
