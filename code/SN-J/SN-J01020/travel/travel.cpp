#include <bits/stdc++h>
using namespace std;
int main(){
	freopen("travel.in",r,stdin);
	freopen("travel.out",w,stdout);
	ios::sync_with_stdio(flase);
	cin.tie(nullptr);
	char c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1;
		if(c2[0]==c4[0]&&c2[1]==c4[1]){
			cout<<1;
				if(c2[2]<='c'&&c4[2]<='c'){
					cout<<1;
					if(c[2]-'A'-1==c[4]-'A'||c[2]-'A'+1==c[4]-'A'){
					cout<<1;
				}else cout<<0;
			}else if(c2[2]>'c'&&c4[2]>'c'){
				cout<<1;
			}else cout<<00;
		}else cout<<000;
	}else{
	cout<<0000;}

return 0;
}
