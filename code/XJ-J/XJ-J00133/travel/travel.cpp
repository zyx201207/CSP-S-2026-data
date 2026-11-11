#include<bits/stdc++.h>
using namespace std;
bool flag1=0,flag2=0,flag3=0,flag4=0;
void pd(char a,char b){
	if(a=='A'){
		if(b=='C' || b=='B'){
			flag3=1;
		}
	}
	else if(a=='B'){
		if(b=='A' || b=='C'){
			flag3=1;
		}
	}
	else if(a=='C'){
		if(b=='A' || b=='B'){
			flag3=1;
		}
	}
	else if(a=='F'){
		if(b=='D'){
			flag3=1;
			flag4=1;
		}
	}
	else if(a=='D'){
		if(b=='F'){
			flag3=1;
			flag4=1;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	char xx,xy;
	xx=s[2];
	xy=ss[2];
	if(c==cc){
		flag1=1;
		string px;
		string py;
		for(int i=0;i<2;i++){
			px+=s[i];
		}
		for(int i=0;i<2;i++){
			py+=ss[i];
		}
		if(px==py){
			flag2=1;
			pd(xx,xy);
		}	
	}
	
	if(flag1==1&&flag2==1&&flag3==1){
		if(abs(xx-xy)==1){
			flag4=1;
		}
	}
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
} 
