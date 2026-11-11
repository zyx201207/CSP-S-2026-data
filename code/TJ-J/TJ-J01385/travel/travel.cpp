#include<bits/stdc++.h>
using namespace std;
long long n,a,b,seata,seatb,xx,yy;
string s,ss,c,d,ans;
char x,y,seatp[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>ss;
	seatp[0]='A';
	seatp[1]='B';
	seatp[2]='C';
	seatp[3]='D';
	seatp[4]='E';
	if(s[0]=='0'){
		c=s[1];
		x=s[2];
	}
	else{
		c=s[0]+s[1];
		x=s[2];
	}
	if(ss[0]=='0'){
		d=ss[1];
		y=ss[2];
	}
	else{
		d=ss[0]+ss[1];
		y=ss[2];
	}
	if(a==b){
		ans[0]='1';
		if(c==d){
			ans[1]='1';
			for(int i=0;i<5;i++){
				if(seatp[i]==x) xx=i+1;
				if(seatp[i]==y) yy=i+1;
			}
			if(xx<=3&&yy<=3){
				ans[2]='1';
				if(xx-yy==1||yy-xx==1) ans[3]='1';
				else ans[3]='0';
			}
			else if(xx>3&&yy>3){
				for(int i=2;i<4;i++){
					ans[i]='1';
				}
			}
			else{
				for(int i=2;i<4;i++){
					ans[i]='0';
				}
			}
		}
		else{
			for(int i=1;i<4;i++){
				ans[i]='0';
			}
		}
	}
	else{
		for(int i=0;i<4;i++){
			ans[i]='0';
		}
	}
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	return 0;
}
