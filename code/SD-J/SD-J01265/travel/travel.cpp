#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc){
		cout<<1;
		if(rs[0]==xs[0]&&rs[1]==xs[1]){
			cout<<1;
			char a=rs[2],b=xs[2];
			if(a>b){
				swap(a,b);
			}
			if('A'<=a&&a<='C'&&'A'<=b&&b<='C'||a=='D'&&b=='F'){
				cout<<1;
				if(a=='A'&&b=='C'){
					cout<<0;
				}
				else{
					cout<<1;
				}
			}
			else{
				cout<<"00";
			}
			
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
