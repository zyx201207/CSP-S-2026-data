#include<bits/stdc++.h>
#define int long long 
using namespace std;
string q,w,e,r;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>q>>w>>e>>r;
	if(q==e){
		cout<<1;
		if(w[0]==r[0] && w[1]==r[1]){
			cout<<1;
			if((w[2]<='D' && w[2]>='F' && r[2]<='D' && r[2]>='F') || (w[2]<='C' && w[2]>='A' && r[2]<='C' && r[2]>='A')){
				cout<<1;
				if(abs(w[2]-r[2])==1){
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else {
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
02 01A 02 01B
02 01C 02 01A



*/
