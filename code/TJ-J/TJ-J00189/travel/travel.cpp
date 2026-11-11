#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d='A';
	string x,y;
	cin>>a>>x>>c>>y;
	b=x[1]-48+(x[0]-48)*10;
	d=y[1]-48+(y[0]-48)*10;
	if(a==c){
		cout<<"1";
		if(b==d){
			cout<<"1";
			if(x[2]<=67&&y[2]<=67||x[2]>67&&y[2]>67){
				cout<<"1";
				if(x[2]+1==y[2]||x[2]-1==y[2]){
					cout<<"1";
				}else{
					cout<<"0";
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
//lower_bound
