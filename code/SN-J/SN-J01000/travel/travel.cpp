#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string c,s,x,y;
	cin>>c>>s>>x>>y;
	bool a=1,b=1,d=1,e=1;
	for(int i=0;i<c.size();i++){
		if(c[i]!=x[i]){
			a=0;
			cout<<0<<0<<0<<0;
			return 0;
		}
	}
	for(int i=0;i<s.size()-1;i++){
		if(s[i]!=y[i]){
			b=0;
			cout<<a<<0<<0<<0;
			return 0;
		}
	}
	int len=s.size();
	int xy=s[len-1];
	int yx=y[len-1];
	if(xy=='C'&&yx=='D'||yx=='C'&&xy=='D'){
		cout<<a<<b<<0<<0;
		return 0;
	}
	if(xy-yx>2&&yx-xy>2){
		d=0;
		cout<<a<<b<<0<<0;
		return 0;
	}
	if(xy-yx!=1&&yx-xy!=1){
		e=0;
	}
	cout<<a<<b<<d<<e;
	
	
	return 0;
}
