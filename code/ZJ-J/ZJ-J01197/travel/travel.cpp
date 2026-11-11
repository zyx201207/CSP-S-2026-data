#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string ax,bx,az,bz,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>ax>>az>>bx>>bz;
	if(ax==bx){
		if(az[0]==bz[0]&&az[1]==bz[1]){
			int za=az[2]-'A',zb=bz[2]-'A';
			if(za>=0&&za<=2&&zb>=0&&zb<=2||za>=3&&za<=4&&zb>=3&&zb<=4){
				if(abs(za-zb)==1){
					cout<<1111;
				}
				else cout<<1110;
			}
			else cout<<1100;
		}
		else cout<<1000;
	}else{
		cout<<"0000";
	}
	return 0;
}
