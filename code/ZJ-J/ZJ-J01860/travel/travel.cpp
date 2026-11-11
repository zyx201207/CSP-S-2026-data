#include<bits/stdc++.h>
using namespace std;
const int N=5;
char x[N],y[N],a[N],b[N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x;
	cin>>y;
	cin>>a;
	cin>>b;
	if(strcmp(x,a)==0){
		if(strncmp(y,b,2)==0){
			if((y[2]=='D'&&b[2]=='F')||(y[2]=='F'&&b[2]=='D')||(y[2]>='A'&&y[2]<='C'&&b[2]>='A'&&b[2]<='C')){
				if((y[2]=='D'&&b[2]=='F')||(y[2]=='F'&&b[2]=='D'))cout<<"1111";
				else if((y[2]=='C'&&b[2]=='B')||(b[2]=='C'&&y[2]=='B'))cout<<"1111";
				else if((y[2]=='B'&&b[2]=='A')||(b[2]=='B'&&y[2]=='A'))cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
