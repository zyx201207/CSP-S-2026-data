#include<bits/stdc++.h>

using namespace std;

string rc,rs,xc,xs;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc){
		cout<<1;
		string a="",b="";
		for(int i=0;i<2;i++){
			a=a+rs[i];
			b=b+xs[i];
		}
		if(a==b){
			cout<<1;
			int tmp1=int(rs[2]),tmp2=int(xs[2]);
			if((tmp1<=67&&tmp2<=67)||(tmp1>67&&tmp2>67)){
				cout<<1;
				if(abs(int(rs[2])-int(xs[2]))!=1||(rs[2]=='C'&&xs[2]=='D')||(xs[2]=='C'&&rs[2]=='D')){
					cout<<0;
				}
				else cout<<1;
			}
			else cout<<"00";
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
