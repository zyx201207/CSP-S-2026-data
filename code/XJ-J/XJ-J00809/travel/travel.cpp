#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rx,xc,xx;
	cin>>rc>>rx>>xc>>xx;
	int c1=rc[0]+rc[1],c2=xc[0]+xc[1];
	if(c1==c2){
		cout<<"1";
		int d1=rx[0]+rx[1],d2=xx[0]+xx[1];
		if(d1==d2){
			cout<<"1";
			int e1=rx[2]-'A'+1,e2=xx[2]-'A'+1;
			
			if(e1<e2){
				swap(e1,e2);
			}
			//cout<<endl<<e1<<" "<<e2;
			//return 0;
			if(e1<=3 && e2<=3){
				cout<<"1";
				if(e1-e2==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(e1>3 && e2>3){
				cout<<"11";
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
