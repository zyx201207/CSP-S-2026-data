#include<bits/stdc++.h>
using namespace std;
#define TESTING
//#define HAND_PATH
void FREOPEN(const string& s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
namespace{
void solve(){
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000\n";
		return;
	}
	cout<<"1";
	if(b.substr(0,2)!=d.substr(0,2)){
		cout<<"000\n";
		return;
	}
	char x=b.back(),y=d.back();
	cout<<"1";
	if(!((x<='C'&&y<='C')||(x>='D'&&y>='D'))){
		cout<<"00\n";
		return;
	}
	cout<<"1";
	if(abs(x-y)!=1){
		cout<<"0\n";
		return;
	}
	cout<<"1\n";
}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
#if !defined(NON_JUDGE) || defined(TESTING)
	FREOPEN("travel");
#elif defined(HAND_PATH)
	string path;
	cin>>path;
	FREOPEN(path);
#endif
	solve();
	return 0;
}
