#include <bits/stdc++.h>
using namespace std;
string r,rl,x,xl;
char d[6]={'1','A','B','C','D','E'};
bool f=true,ff=true,fff=true;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r>>rl>>x>>xl;
    for(int i=0;i<=1;i++){
		if(r[i]!=x[i]){
			f=false;
    		}
		}
	if(f==true){cout<<1;}
	else{cout<<0;}
	for(int i=0;i<=1;i++){
		if(rl[i]!=xl[i]){
			ff=false;
			}
		}
	if(f==true&&ff==true){cout<<1;}
	else{cout<<0;}
	int m,n;
	for(int i=1;i<=5;i++){
		if(rl[2]==d[i]){
			m=i;
			}
		if(xl[2]==d[i]){
			n=i;
			}
		}
		int j=0;
	if((m<=3&&n<=3)||(m>=4&&n>=4)){
		j=1;
		}
	if(f==true&&ff==true&&j==1){cout<<1;}
	else{cout<<0;fff=false;}
	if(abs(n-m)==1&&fff==true){
		cout<<1;
		}
	else{
		cout<<0;}
    return 0;
}
