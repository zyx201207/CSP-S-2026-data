#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

const int N=1e5+10;

int side(char c){
	if(c<'D')return 0;
	else return 1;
}

bool check(pair<char,char> a){
	return (a==make_pair('A','B')||a==make_pair('B','C')||a==make_pair('D','F'));
}

void solve(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return ;
	}
	cout<<1;
	if(!(s1[0]==s2[0]&&s1[1]==s2[1])){
		cout<<"000"<<endl;
		return ;
	}
	cout<<1;
	char r=s1[2],x=s2[2];
	if(side(r)!=side(x)){
		cout<<"00"<<endl;
		return;
	}
	cout<<1;
	if(check({r,x})||check({x,r}))cout<<1<<endl;
	else cout<<0<<endl;
	return;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	solve();

	return 0;
}

