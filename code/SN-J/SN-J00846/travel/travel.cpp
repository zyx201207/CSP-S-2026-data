#include<bits/stdc++.h>
#define int long long
using namespace std;
string rc,rs,xc,xs;
string s;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//许子衿 SN-J00846 西安翱翔中学 
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc){
		cout<<1;
		if((rs[0]+rs[1])==(xs[0]+xs[1])){
			cout<<1;
			if(rs[2]<'D'&&xs[2]<'D'){
				cout<<1;
				s=rs[2]+xs[2];
				if(s=="AB"||s=="BA"||s=="BC"||s=="CB"){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(rs[2]>='D'&&xs[2]>='D'){
				cout<<11;
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
