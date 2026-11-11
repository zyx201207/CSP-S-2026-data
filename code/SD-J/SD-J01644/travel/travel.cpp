#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string w,x,y,z;
	cin>>w>>x>>y>>z;
	if(w==y){
		cout<<1;
		if(x[0]+x[1]==z[0]+z[1]){
			cout<<1;
			if((x[2]<='C'&&z[2]<='C')||(x[2]>='D'&&z[2]>='D')){
				cout<<1;
				if((abs(x[2]-z[2])==1&&x[2]!='F'&&z[2]!='F')||((x[2]=='F'&&z[2]=='D')||(z[2]=='F'&&x[2]=='D'))){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}else{
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
