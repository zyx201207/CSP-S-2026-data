#include<bits/stdc++.h>
using namespace std;
string c[3],s[3]; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1]!=c[2]){
		cout<<"0000";
	}else{
		cout<<1;
		if(s[1][0]==s[2][0] && s[1][1]==s[2][1]){//Í¬Ò»ÅÅ
			cout<<1;
			char x=s[1][2],y=s[2][2];
			if(x>y) swap(x,y);//x<y
			if((x<='C' && y<='C')||(x=='D' && y=='F')){
				cout<<1;
				if(char(x+1)==y) cout<<1;
				else cout<<0;
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
	return 0;
}	
