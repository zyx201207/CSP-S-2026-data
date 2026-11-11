#include<bits/stdc++.h>
using namespace std;
int a,b,d,e;
char c,f;
int main(){
	freopen("travel.in","r",stdin),freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d>>e>>f;
	if(a==d){
		if(b==e){
			if((c<'D'&&f<'D')||(c>'C'&&f>'C')){
				if(c>f)swap(c,f);
				if((c=='A'&&f=='B')||(c=='B'&&f=='C')||(c=='D'&&f=='F'))cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
