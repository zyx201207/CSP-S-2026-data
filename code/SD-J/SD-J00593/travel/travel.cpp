#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pii pair<int,int>
using namespace std;
int cr;string sr;//³µÏá¡¢×ùÎ»
int cx;string sx;
pair<int ,int> nod(string s){
	int l=int(s[0]-'0')*10+int(s[1]-'0');
	int r=int(s[2]-'A'+1);
	return make_pair(l,r); 
}
bool ce(int x){
	if(1<=x&&x<=3)return 0;
	return 1;
}
bool out(bool f,int n){
	if(f){
		cout<<"1";
	}else{
		for(int i=1;i<=n;i++){
			cout<<"0";
		}return 1;
	}return 0;
}
void solve(){
	cin >> cr >> sr >> cx >> sx;
	if(out(cr==cx,4))return;
	pii r=nod(sr);
	pii x=nod(sx);
	if(out(r.fi==x.fi,3))return;
	if(out(ce(r.se)==ce(x.se),2))return;
	if(out(abs(r.se-x.se)==1,1))return;
}
signed main(){
	IOS;
	freopen("travel.in", "r",stdin);
	freopen("travel.out","w",stdout);
    //int t;cin >> t;while(t--)
    solve();
    return 0;
}
