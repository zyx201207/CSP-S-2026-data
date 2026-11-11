#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int x=int(b[2]),y=int(d[2]);
	
	if(a==c){
		cout<<'1';
		if(b[1]==d[1]&&b[0]==d[0]){
			cout<<'1';
			if(x<=67&&y<=67||x>=68&&y>=68){
				cout<<'1';
				if(abs(x-y)==1){
					cout<<'1';
				}
				else{
					cout<<'0';
				}
			}
            else{
            	cout<<'0'<<'0';
			
			}
			}
		
		else{
			cout<<'0'<<'0'<<'0';

		}
	
	}
	else{
		cout<<'0'<<'0'<<'0'<<'0';
	}


return 0;
}
