#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string s;
	int ans1=0,ans2=0,ans3=0,daan=0;
	if(a==c){
		ans1=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			ans2=1;
			if(((b[2]>='A'&&b[2]<='C')&&(d[2]>='A'&&d[2]<='C'))||((b[2]=='D'&&b[2]=='F')&&(d[2]=='D'&&d[2]=='F'))){
				ans3=1;
				if((b[2]>='A'&&b[2]<='C')&&(d[2]>='A'&&d[2]<='C')){
			        if(b[2]-d[2]==1||d[2]-b[2]==1) daan=1;
		        }
		        if((b[2]=='D'&&d[2]=='F')||(d[2]=='D'&&b[2]=='F')){
		        	daan=1;
				}
			}
		}
	}
	cout<<ans1<<ans2<<ans3<<daan;
	return 0;
} 
