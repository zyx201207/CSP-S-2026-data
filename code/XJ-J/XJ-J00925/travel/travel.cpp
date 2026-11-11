#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in",'r',stdin);
	freopen("travel.out",'w',stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		if(b[0]==d[0] && b[1]==d[1]){
			if(b[2]-d[2]<=4){
				if(b[2]-d[2]==1||b[2]-d[2]==-1){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}