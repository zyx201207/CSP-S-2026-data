#include<bits/stdc++.h>

#define ll long long
#define repeat(n) for(int _=0;_<n;++_)

using namespace std;

struct item{
	int a;
	char c;
};

int n,ina;
char inc;
string s="";

vector<item> v;

int main(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	//---input---
	
	cin>>n;

	repeat(n){
		cin>>ina>>inc;
		v.push_back({ina,inc});
	}

	int len=(int)s.length();

	ll res=0;

	while(!v.empty()){

		int m,o,las=int(v.size())-1;

		if(
			v[0].a >= v[las].a
		){m=las;o=0;}
		else {m=0;o=las;}

		if(v[0].c!=v[las].c)res+=v[m].a;

		
		v[o].a-=v[m].a;
		v.erase(v.begin()+m);

	}
	
	cout<<res<<'\n';

	// O(n) worstly.

	return 0;
}