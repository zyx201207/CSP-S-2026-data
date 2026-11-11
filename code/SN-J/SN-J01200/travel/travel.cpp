#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define pi pair<int,int>
#define vi vector<int> 
#define mkp(a,b) make_pair(a,b)
#define inf 0x3f3f3f3f3f3f3f3fll
#define ll long long
const int N=1e5+5,mo=1e9+7;
int n,m,k,a[N]; 
int qpow(int n,int m,int mo){
	int sum=1;
	while(m){
		if(m&1) sum=1ll*sum*n%mo;
		n=n*n%mo;
		m>>=1;
	}
	return sum;
}
string a1,a2,b1,b2,c=" ABCDE";
void solve(){
	cin>>a1>>a2>>b1>>b2;
	if(a2[2]=='F') a2[2]='E';
	if(b2[2]=='F') b2[2]='E';
	if(a1==b1){
		cout<<1;
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			cout<<1;
			int f=0;
			rep(i,1,3) rep(j,1,3) if(a2[2]==c[i]&&b2[2]==c[j]) f=1;
			rep(i,4,5) rep(j,4,5) if(a2[2]==c[i]&&b2[2]==c[j]) f=1;
			if(f){
				cout<<1;
				if(abs(int(a2[2])-int(b2[2]))==1) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
//RP++!
