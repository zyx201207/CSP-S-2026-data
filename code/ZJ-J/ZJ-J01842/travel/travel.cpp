#include <bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<1;
		string a="",b="";
		for(int i=0;i<=1;i++){
			a+=sr[i];
			b+=sx[i];
		}
		if(a==b){
			cout<<1;
			if((sr[2]<='C'&&sx[2]<='C')||(sr[2]>='D'&&sx[2]>='D')){
				cout<<1;
				if(abs(sr[2]-sx[2])==1){
					cout<<1;
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}