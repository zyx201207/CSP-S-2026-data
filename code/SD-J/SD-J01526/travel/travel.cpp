#include<bits/stdc++.h>
using namespace std;

int a,b,c,d,e,f,g,h;
char t;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>t;
	h=t-'A'+1;
	if(h==6){
		h--;
	}
	if(h<=3){
		c=1;
	}else{
		c=2;
	}
	cin>>d>>e>>t;
	g=t-'A'+1;
	if(g==6){
		g--;
	}
	if(g<=3){
		f=1;
	}else{
		f=2;
	}
	if(a==d){
		cout<<1;
		if(b==e){
			cout<<1;
			if(f==c){
				cout<<1;
				if(abs(g-h)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
