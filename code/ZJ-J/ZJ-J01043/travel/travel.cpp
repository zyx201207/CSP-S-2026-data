#include<bits/stdc++.h>
using namespace std;
int x,y;
string sx,sy;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>x>>sx>>y>>sy;
	if(x!=y)cout<<"0000";
	else{
		if(sx[0]!=sy[0]||sx[1]!=sy[1])cout<<"1000";
		else{
			if((sx[2]<='C'&&sy[2]>'C')||(sx[2]>'C'&&sy[2]<='C'))cout<<"1100";
			else{
				if(abs(sx[2]-sy[2])==1)cout<<"1111";
				else cout<<"1110";
			} 
		}
	}
	return 0;
}
