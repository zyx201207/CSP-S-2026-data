#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
string x,y;
char h,g;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>cc>>s>>ss;
	for(int i=0;i<cc.size();++i){
		if(i<=1) x+=cc[i];
		else h+=cc[i];
	}
	for(int i=0;i<ss.size();++i){
		if(i<=1) y+=ss[i];
		else g+=ss[i];
	}
	if(c==s){
		cout<<'1';
		if(x==y){
			cout<<'1';
			if(h>='A'&&h<='C'&&g>='A'&&g<='C'){
				cout<<'1';
				if(h=='A'&&g=='C'||h=='C'&&g=='A'){
					cout<<'0';
				}
				else{
					cout<<1;
				}
			}
			else if(h>='D'&&h<='F'&&g>='D'&&g<='F'){
				cout<<'1';
				if(h=='D'&&g=='F'||h=='F'&&g=='D'){
					cout<<'1';
				}
				else{
					cout<<'0';
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
