#include<bits/stdc++.h>
using namespace std;
string ar,ax,br,bx,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ar>>br>>ax>>bx;
	if(ar==ax)
	cout<<1;
	else{
	cout<<"0000";
	return 0;
	}
	c=bx[0]+bx[1];
	d=br[0]+br[1];
	if(c==d)
		cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char k=br[2],l=bx[2];
	if('A'<=k&&k<='C'&&'A'<=l&&l<='C')
	cout<<1;
	else if('D'<=k&&k<='E'&&'D'<=l&&l<='E')
	cout<<1;
	else {
	cout<<"00";
	return 0;
	}
	int g=k,h=l;
	if(abs(g-h)==1)
	cout<<1;
	else 
	cout<<0;
	return 0;
}
