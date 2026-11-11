#include<bits/stdc++.h>
using namespace std;
#define TESTING
//#define HAND_PATH
void FREOPEN(const string& s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
namespace{
using ll=long long;
constexpr int N=200005;
ll v[N];
char ch[N];
void solve(){
	int n;
	cin>>n;
	ll len=0;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>ch[i];
		len+=v[i];
	}
	ll ls=0,rs=0,ans=0;
	int l=0,r=n+1;
	while(r-l>1){
		
		if(ls<=rs){
			ll sub=v[++l];
			if(ch[l]!=ch[r])ans+=min(rs-ls,sub);
			ls+=sub;
		}
		else{
			ll sub=v[--r];
			if(ch[l]!=ch[r])ans+=min(ls-rs,sub);
			rs+=sub;
		}
		
		//cout<<ls<<" "<<rs<<" "<<l<<" "<<r<<" "<<ans<<endl;
	}
	//cout<<ls<<" "<<rs<<endl;
	cout<<ans;
}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
#if !defined(NON_JUDGE) || defined(TESTING)
	FREOPEN("string");
#elif defined(HAND_PATH)
	string path;
	cin>>path;
	FREOPEN(path);
#endif
	solve();
	return 0;
}
