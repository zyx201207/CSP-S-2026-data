#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;
int g[10] = {1,1,1,2,0,2};

bool AC(int x,int y){
	if((x == 3 && y == 5) || (x == 5 && y == 3)){
		return 1;
	}
	
	if(((x == 0 || x == 2) && y == 1) || ((y == 0 || y == 2) && x == 1)){
		return 1;
	}
	
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	string e = "",h = "";
	e += c[0];
	e += c[1];
	h += d[0];
	h += d[1];
	int s = c[2] - 'A',t = d[2] - 'A';
	if(a == b){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(a == b && e == h){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(a == b && e == h && g[s] == g[t]){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(a == b && e == h && g[s] == g[t] && AC(s,t) == 1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
