#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		bool flag=1;
		for(int i=0;i<2;i++){
			if(b[i]!=d[i]){
				flag=0;
				break;
			}
		}
		if(flag){
			cout<<"1";
			bool _1=(b[2]<='C'),_2=(d[2]<='C');
			if(_1==_2){
				cout<<"1";
				char mn=min(b[2],d[2]),mx=max(b[2],d[2]);
				if(mn=='A'&&mx=='B'||mn=='B'&&mx=='C'||mn=='D'&&mx=='F'){
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
