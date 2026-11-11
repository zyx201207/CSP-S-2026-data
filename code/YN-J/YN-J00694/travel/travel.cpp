#include<iostream>
using namespace std;//年少自仗心胆，扬名何须待时！
int main(){
	freopen("travel.in","r",stdin),freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	string a,b,c,d;cin>>a>>b>>c>>d;
	if(a==c){
		if(b.substr(0,2)==d.substr(0,2)){
			int x=b[2]-'A',y=d[2]-'A';
			if(((x<3)&&(y>=3))||((y<3)&&(x>=3)))cout<<"1100";
			else {
				if(x==y-1||y==x-1||x+y==8)cout<<"1111";
				else cout<<"1110";
			}
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;}
