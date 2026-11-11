#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
char v,y;
bool check1(){
	return b==d;
}
bool check2(){
	if((v>'C'&&y>'C')||(v<='C'&&y<='C')) return true;
	else return false;
}
bool check3(){
	if(v>'C'&&y>'C') return true;
	else if((int)abs((int)v-(int)y)==1ll) return true;
	else return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	v=b[2];
	y=d[2];
	b.erase(b.size()-1);
	d.erase(d.size()-1);
	if(a==c){
		cout<<"1";
		if(check1()){
			cout<<"1";
			if(check2()){
				cout<<"1";
				if(check3()){
					cout<<"1";
				}else{
					cout<<"0";
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
