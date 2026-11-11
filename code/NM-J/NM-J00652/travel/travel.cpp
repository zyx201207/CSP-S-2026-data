#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string a,b,c,d,x;
	int s1=0,s2=0,v;
	int l;
    cin >> a >> b >> c >> d;
    s1=b[2];
    s2=d[2];
	v=max(s1,s2)-min(s1,s2);
    if(a==c){
    	x+='1';
    	if(b[0]==d[0] && b[1]==d[1]){
    		x+='1';
    		if(v==1){
    			x+='1';
			}else{
				x+='0';
			}
		}else{
			x+='0';
		}
	}else{
		x+='0';
	}
	cout << x;
    return 0;
}

