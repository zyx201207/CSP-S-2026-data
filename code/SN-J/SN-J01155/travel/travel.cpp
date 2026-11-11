#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//gxez zhangshuchang
string a,b,c,d;
char near[4]={'A','B','C','N'};
char near2[4]={'D','F','N'};
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
		if((b[2]=='C'||b[2]=='B'||b[2]=='A')&&(d[2]=='C'||d[2]=='B'||d[2]=='A')){
			cout<<1;
			if((b[2]=='C'&&d[2]=='B')||(d[2]=='C'&&b[2]=='B')){
				cout<<1;
			}
			else if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')){
				cout<<1; 
			}
			else if((b[2]=='C'&&d[2]=='A')||(b[2]=='A'&&d[2]=='C')){
				cout<<0;
			}
		}
		else if((b[2]=='F'||b[2]=='D')&&(d[2]=='F'||d[2]=='D')){
			
			cout<<"11";
		}
		else{
			cout<<"00";
		}
	}
	else{
		cout<<"000";
		return 0;
	}
	
	return 0;
}
