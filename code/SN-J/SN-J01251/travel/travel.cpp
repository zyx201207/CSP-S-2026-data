#include<bits/stdc++.h>
using namespace std;
bool ans1=0,ans2=0,ans3=0,ans4=0;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans1=1;
		if(b[0]+b[1]==d[0]+d[1]){
			ans2=1;
			if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')) ans3=1;
			if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')) ans3=1;
			if(b[2]-d[2]==1||b[2]-d[2]==-1) ans4=1;
			if(b[2]=='C'&&d[2]=='D') ans4=0;
			if(b[2]=='D'&&d[2]=='C') ans4=0;	
		}
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
} 
// T1
