#include<bits/stdc++.h>
using namespace std;
string cx,sx,cy,sy;
char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sx>>cy>>sy;
	x=sx[2];
	y=sy[2];
	if(cx==cy){
		cout<<1;
		if(sx[0]==sy[0]&&sx[1]==sy[1]){
			cout<<1;
			if((x<='C'&&y<='C')||(x>='D'&&y>='D')){
				cout<<1;
				if(x>='D'||x+1==y||y+1==x){
					cout<<1;
				}
				else  cout<<"0";
			}
			else  cout<<"00";
		}
		else  cout<<"000";
	}
	else  cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
