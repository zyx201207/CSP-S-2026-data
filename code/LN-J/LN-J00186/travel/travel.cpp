#include<bits/stdc++.h>
using namespace std;
string c1,c2,x1,x2;
int a[5]={0,0,0,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>c2>>x1>>x2;
	if(c1==x1){
		cout<<"1";
		if(c2.substr(0,2)==x2.substr(0,2)){
			cout<<"1";
			if(a[c2.back()-'A']==a[x2.back()-'A']){
				cout<<"1";
				if(abs((c2[2]-'A')-(x2[2]-'A'))==1)cout<<"1";
				else                             cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else      cout<<"0000";
	
	return 0;
}
