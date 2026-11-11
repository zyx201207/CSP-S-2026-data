#include<bits/stdc++.h>
using namespace std;
#define PID "travel"
#define FI freopen(PID".in","r",stdin);
#define FO freopen(PID".out","w",stdout);
string cx,sx,cy,sy;
int zx,px,wx,zy,py,wy;
bool b;
int main(){
	FI;FO;
	cin>>cx>>sx>>cy>>sy;
	if(cx.size()==2){
		zx=(cx[0]-'0')*10+(cx[1]-'0');
		if(zx>17||zx<1){
			zx=-1;
		}
	}
	if(cy.size()==2){
		zy=(cy[0]-'0')*10+(cy[1]-'0');
		if(zy>17||zy<1){
			zy=-1;
		}
	}
	if(zx==zy&&zx!=-1){
		cout<<1;
		b=true;
	}else{
		cout<<0;
		b=false;
	}
	if(sx.size()==3){
		px=(sx[0]-'0')*10+(sx[1]-'0');
		if(px>18||px<1){
			px=-1;
		}
		wx=(sx[2]-'A'+1);
		if(wx>5||wx<1){
			wx=-1;
		}
	}
	if(sy.size()==3){
		py=(sy[0]-'0')*10+(sy[1]-'0');
		if(py>18||py<1){
			py=-1;
		}
		wy=(sy[2]-'A'+1);
		if(wy>5||wy<1){
			wy=-1;
		}
	}
	if(b&&px==py&&px!=-1){
		cout<<1;
	}else{
		cout<<0;
		b=false;
	}
	if(b&&((wx<=3&&wx>0&&wy<=3&&wy>0)||(wx>3&&wx<=5&&wy>3&&wy<=5))&&wx!=-1&&wy!=-1){
		cout<<1;
	}else{
		cout<<0;
		b=false;
	}
	if(b&&abs(wx-wy)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
