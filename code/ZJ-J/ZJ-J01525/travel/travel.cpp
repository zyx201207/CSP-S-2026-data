#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		if(b[0]==d[0]&&b[1]==d[1]){
			if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'||b[2]=='E')&&(d[2]=='D'||d[2]=='E'))){
				if(abs((int)b[2]-(int)d[2])==1)   cout<<"1111";
				else   cout<<"1110";
			}
			else   cout<<"1100";
		}
		else   cout<<"1000";
	}
	else   cout<<"0000";
	return 0;
}//最后30min写完T3了,T4有思路但是没时间了,100+100+100+40=340,1=了吧,ovO