#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int a,c;
	string b,d;
	
	cin>>a>>b>>c>>d;
	
	if(a==c){
		cout<<1;
		int t1,t2;
		t1 = (int)b[0] * 10 + (int)b[1];
		t2 = (int)d[0] * 10 + (int)d[1];
		if(t1==t2){
			cout<<1;
			char t3,t4;
			t3 = b[2];
			t4 = d[2];
			bool c1,c2;
			c1 = (t3=='D')|(t3=='F');
			c2 = (t4=='D')|(t4=='F');
			if(c1==c2){
				cout<<1;
				if(abs(t4-t3)==1){
					cout<<1;
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
	
	return 0;
}

