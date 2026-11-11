#include<bits/stdc++.h>

using namespace std;

#define rp(i,j,k) for(int i=(j);i<=(k);i++)
#define pr(i,j,k) for(int i=(j);i>=(k);i--)
#define vi vector<int>
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
void gmin(int &x,int y){x=min(x,y);}
void gmax(int &x,int y){x=max(x,y);}

namespace SOLVE{

string c1,s1,c2,s2;

int f(char c){
	if(c=='A')return 1;
	if(c=='B')return 2;
	if(c=='C')return 3;
	if(c=='D')return 4;
	if(c=='E')return 5;
	return 0;
}

void solve(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<"1";
			int x=f(s1[2]);
			int y=f(s2[2]);
			if(x<=3&&y<=3||x>=4&&y>=4){
				cout<<"1";
				if(abs(x-y)<=1)cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return;
}

}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _=1;//cin>>_;
	while(_--)SOLVE::solve();
	return 0;
}