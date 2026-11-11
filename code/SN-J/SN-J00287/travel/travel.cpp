#include<bits/stdc++.h>
using namespace std;
int rc,xc;
int rp,xp;
char rs,xs;
int a[5];
int main(){
	//wc     |   ‡å 
    //·þÁË   V Orz
	freopen("travel.in","in",std);
	freopen("travel.out","out",_size);
	cin>>rc>>rp>>rs>>xc>>xp>>xs;
	if(rc==xc){
		a[1]=1;
		if(rp==xp){
			a[2]=1;
			if((rs>='D'&&xs>='D')||(rs<'D'&&xs<'D')){
				a[3]=1;
				if(abs(rs-xs)==1){
					a[4]=1;
					}
				}
			}
		}
	
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
}
/*



*/
