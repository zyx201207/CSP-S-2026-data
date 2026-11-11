#include <bits/stdc++.h>
using namespace std;
int a,b,x,y;
string s,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> s >> b >>s2;
	x=s[0]-'0'+s[1]-'0',y=s2[0]-'0'+s2[1]-'0';
	if(a==b){
		cout<<1;
		if(x==y){
			cout<<1;
			if((s[2]>='D'&&s2[2]>='D')||(s[2]<='C'&&s2[2]<='C')){
				cout<<1;
				if(s[2]-s2[2]==1||s[2]-s2[2]==-1){
					cout<<1;
				}else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000"; 
    return 0;
}
