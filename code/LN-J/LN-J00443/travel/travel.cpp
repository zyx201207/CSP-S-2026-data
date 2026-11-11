#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c1,c2,z1,z2;
	char j1,j2;
	cin>>c1>>z1>>j1>>c2>>z2>>j2;
	int y1=j1-'A'+1;
	int y2=j2-'A'+1;
	
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(z1==z2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((y1<=3&&y2<=3)||(y1>3&&y2>3)) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(y1-y2)==1) cout<<1;
	else cout<<0;
	return 0;
}
