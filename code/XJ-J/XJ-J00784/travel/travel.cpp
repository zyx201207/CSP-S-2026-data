#include<bits/stdc++.h>
using namespace std;
string rc,xc,rz,xz;
string re,xe;
int ree,xee,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rz>>xc>>xz;
	if(rc==xc){
		b=1;
		cout<<b;
	}else{
		b=0;
		cout<<b;
	}
	if(b==1){
		string rp=rz,xp=xz;
		rp.erase(2,1);
		xp.erase(2,1);
		if(rp==xp){
			cout<<b;
		}else{
			b=0;
			cout<<0;
		}
	}else cout<<b;
	if(b==1){
		re=rz,xe=xz;
		re.erase(0,2);
		xe.erase(0,2);
		if(re=="A"||re=="B"||re=="C"){
			ree=1;
		}else{
			ree=2;
		}
		if(re=="A"||re=="B"||re=="C"){
			xee=1;
		}else{
			xee=2;
		}
		if(ree==xee){
			cout<<b;
		}else b=0;			
	}else cout<<b;
	if(b==1){
		if(re=="A")ree=1;
		if(re=="B")ree=2;
		if(re=="C")ree=3;
		if(re=="D")ree=5;
		if(re=="F")ree=6;
		if(xe=="A")xee=1;
		if(xe=="B")xee=2;
		if(xe=="C")xee=3;
		if(xe=="D")xee=5;
		if(xe=="F")xee=6;
		if(ree-1==xee||ree+1==xee){
			cout<<b;
		}	
	}else cout<<b;
	return 0;
}
