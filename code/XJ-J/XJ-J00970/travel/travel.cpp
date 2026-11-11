#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,ans;
	cin>>a>>b>>c>>d;
	bool x=0,y=0,z=0;
	if(a==c){
		ans+='1';
		x=1;
	}else{
		ans+='0';
	}
	if(x&&b[0]==d[0]&&b[1]==d[1]){
		ans+='1';
		y=1;
	}else{
		ans+='0';
	}
	if(x&&y&&((b[2]-'A'<3&&d[2]-'A'<3)||(b[2]-'A'>=3&&d[2]-'A'>=3))){
		ans+='1';
		z=1;
	}else{
		ans+='0';
	}
	if(x&&y&&z){
		if(b[2]=='A'){
			if(d[2]=='B'){
				ans+='1';
			}else{
				ans+='0';
			}
		}else if(b[2]=='B'){
			if(d[2]=='A'||d[2]=='C'){
				ans+='1';
			}else{
				ans+='0';
			}
		}else if(b[2]=='C'){
			if(d[2]=='B'){
				ans+='1';
			}else{
				ans+='0';
			}
		}else if(b[2]=='D'){
			if(d[2]=='F'){
				ans+='1';
			}else{
				ans+='0';
			}
		}else if(b[2]=='F'){
			if(d[2]=='D'){
				ans+='1';
			}else{
				ans+='0';
			}
		}else{
			ans+='0';
		}
	}else{
		ans+='0';
	}
	cout<<ans;
	return 0;
} 
