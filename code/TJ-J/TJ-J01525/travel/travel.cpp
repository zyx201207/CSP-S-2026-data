#include <bits/stdc++.h> 

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string sa,sb,ca,cb;
	cin>>sa>>ca>>sb>>cb;
	//
	if(sa==sb)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}

	string pa="",pb="";
	pa+=ca[0];
	pa+=ca[1];
	pb+=cb[0];
	pb+=cb[1];
	//
	if(pa==pb){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}

	char za=ca[2],zb=cb[2];
	//cout<<za<<" "<<zb;
	//
	if((za<='C'&&zb<='C')||(za>='D'&&zb>='D')){
		cout<<1;
		if(za<='C'&&zb<='C'){
			if(abs(za-zb)==1){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<1; 
		}
	}else{
		cout<<"00";
		return 0;
	}
	return 0;
}
