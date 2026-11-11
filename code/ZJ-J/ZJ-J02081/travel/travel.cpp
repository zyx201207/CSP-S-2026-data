#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a!=b){
		cout<<"0000"<<endl;
	}
	else{
		cout<<"1";
		if(int(c[0])!=int(d[0])||int(c[1])!=int(d[1])){
			cout<<"000"<<endl;
		}
		else{
			cout<<"1";
			if(c[2]=='D'&&d[2]!='F'||c[2]=='F'&&d[2]!='D'||d[2]=='D'&&c[2]!='F'||d[2]=='D'&&c[2]!='F'){
				cout<<"00"<<endl;
			}
			else if(c[2]=='D'&&d[2]=='F'||d[2]=='D'&&c[2]=='F'){
				cout<<"11";
			}
			else{
				cout<<"1";
				if(c[2]!='B'&&d[2]!='B'){
					cout<<"0"<<endl;
				}
				else{
					cout<<"1"<<endl;
				}
			}
		}
	}
	return 0;
}
