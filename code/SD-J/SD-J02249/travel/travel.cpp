#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string c,x,cr,xr;
	cin>>c>>cr>>x>>xr;
	if(c==x){
	    cout<<"1";
    }else{
    	cout<<"0000";
    	return 0;
	}
	int f=0;
	if(cr[0]==xr[0]&&cr[1]==xr[1]){
		cout<<"1";
		if(cr[2]=='A'){
			if(xr[2]=='B'||xr[2]=='c'){
				f=1;
				cout<<"1";
			}
		}else if(cr[2]=='B'){
			if(xr[2]=='A'||xr[2]=='c'){
				f=1;
				cout<<"1";
			}
		}else if(cr[2]=='C'){
			if(xr[2]=='A'||xr[2]=='B'){
				f=1;
				cout<<"1";
			}
		}else if(cr[2]=='D'){
			if(xr[2]=='E'){
				f=1;
				cout<<"1";
			}
		}else if(cr[2]=='E'){
			if(xr[2]=='D'){
				f=1;
				cout<<"1";
			}
		}
	}else{
		cout<<"000";
		return 0;
	}
	if(f==0){
	   cout<<"00";
	   return 0;
    }
    if(xr[2]=='A'&&cr[2]=='C'){
	   cout<<"0";
    }else if(xr[2]=='C'&&cr[2]=='A'){
	   cout<<"0";
    }else{
    	cout<<"1";
	}
	return 0;
} 
