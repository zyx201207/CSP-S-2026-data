#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;char zd1,zd2,zd3,zd4,zd5,zd6;
    cin>>c1;cin>>zd1>>zd2>>zd3;
	cin>>c2;cin>>zd4>>zd5>>zd6;

	
	if(c1 == c2) {
		cout<<"1";
		//1
		if(zd1 == zd4){
		if(zd2 == zd5) cout<<"1";
		else cout<<"00";
		//2
		if( (zd2 < 3 && zd5 < 3) || (zd2 > 3 && zd5 > 3) ){
			cout<<"1";
			//3
			if(((zd3 == 'A') and (zd6 == 'B')) or ((zd3 == 'B') and (zd6 == 'A')) or ((zd3 == 'B') and (zd6 == 'C')) or ((zd3 == 'C') and (zd6 == 'B')) or ((zd3 == 'D') and (zd6 == 'F')) or ((zd3 == 'F') and (zd6 == 'B')))cout<<1;
			else cout<<0;
			
		}
		else cout<<"000";
		
	}
	else cout<<"000";
	
	}
	else cout<<"0000";
	
	
	return 0;
}
