#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			int z,s;
			if(b[2]>='D'){
				z=1;
			}else{
				z=-1;
			}
			if(d[2]>='D'){
				s=1;
			}else{
				s=-1;
			}
			if(z*s==1){
				cout<<1;
				if(abs(d[2]-b[2]==1)){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
