#include <bits/stdc++.h>
using namespace std;
int x,y,f[150];
string a,b,aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	f['A']=f['B']=f['C']=1;
	f['D']=f['F']=2;
	if(a==b){
		cout<<1;
		if(aa[0]+aa[1]==bb[0]+bb[1]){
			cout<<1;
			x=f[aa[2]];y=f[bb[2]];
			if(x==y){
				cout<<1;
				if(aa[2]=='A'&&bb[2]=='B')cout<<1;
				else if(aa[2]=='B'&&bb[2]=='A')cout<<1;
				else if(aa[2]=='B'&&bb[2]=='C')cout<<1;
				else if(aa[2]=='C'&&bb[2]=='B')cout<<1;
				else if(aa[2]=='D'&&bb[2]=='F')cout<<1;
				else if(aa[2]=='F'&&bb[2]=='D')cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else{
			cout<<"000";
		}
	}
	else cout<<"0000";
	return 0;
}
