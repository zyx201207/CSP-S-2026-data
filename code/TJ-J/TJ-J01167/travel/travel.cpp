#include <bits\stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
string qian(string s){
	string o;
	for(int i=0;i<s.size()-1;i++){
		o+=s[i];
	}
	return o;
}
bool tong(string s){
	//s.size()-1
	if(s[s.size()-1]=='A'||s[s.size()-1]=='B'||s[s.size()-1]=='C'){
		return 1;
	}else{
		return 0;
	}
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(qian(b)==qian(d)){
			cout<<1;
			if(tong(b)==tong(d)){
				cout<<1;
				if(abs((b[b.size()-1]-d[d.size()-1]))==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
