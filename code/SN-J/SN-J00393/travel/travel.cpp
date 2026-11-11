#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int ax=a[0]-'0'+a[1]-'0',bx=c[0]-'0'+c[1]-'0';
	int ay=a[2],by=c[2];
	if(a==c){
		cout<<"1";
		if(ax==bx){
			cout<<"1";
			if((ay<='c' && by<='c') || (ay>'c' && by>'c')){
				cout<<"1";
				if(abs(ay-by)==1){
					cout<<"1";
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
	
}
