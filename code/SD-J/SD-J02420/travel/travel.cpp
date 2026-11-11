#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rz,xz,rb,xb;
	string ans;
	cin>>rz>>rb>>xz>>xb;
	char c=xb[2],d=rb[2];
	if(rz!=xz){
		cout<<"0000";
		return 0;
	}
	if(xb.erase(2)!=rb.erase(2)){
		cout<<"1000";
		return 0;
	}
	int w=0,r=0;
	if(c=='A'||c=='B'||c=='C'){w=1;}
	if(d=='A'||d=='B'||d=='C'){r=1;}
	if(d=='F'||d=='D'){r=2;}
	if(c=='F'||c=='D'){w=2;}
	if(r!=w){
		cout<<"1100";
		return 0;
	}
	bool p=true;
	if((c=='A'&&d=='B')||(c=='B'&&d=='A')||(c=='C'&&d=='B')||(c=='B'&&d=='C')||(c=='F'&&d=='D')||(c=='D'&&d=='F')){
		cout<<"1111";
		p=false;
	}
	if(p){
		cout<<1110;
	}
	return 0;
}
