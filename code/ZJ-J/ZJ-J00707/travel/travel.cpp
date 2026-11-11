#include<bits/stdc++.h>
using namespace std;
string a,az,b,bz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>az>>b>>bz;
	if(a==b){
		cout<<1;
		if(az[0]==bz[0]&&az[1]==bz[1]){
			cout<<1;
			if(az[2]>='D'&&bz[2]>='D'){
				cout<<11;
			}else if(az[2]<='C'&&bz[2]<='C'){
				cout<<1;
				if(az[2]!='B'&&bz[2]!='B'){
					cout<<0;
				}else{
					cout<<1;
				}
			}else{
				cout<<0<<0;
			}
			
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
