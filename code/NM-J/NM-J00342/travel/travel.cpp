#include<bits/stdc++.h>
#define int long long
#define go(x)(cout<<x<<'\n',void())
#define go1(x)(cout<<x,void())
#define vi vector<int>
#define in(x)(cin>>x,void())
#define in1(x,y)(cin>>x>>y,void())
#define in2(x,y,z)(cin>>x>>y>>z,void())
#define pb push_back
#define vc vector<char>
using namespace std;
void solve(){
    string s1,s2,c1,c2;
    in1(s1,s2);
    in1(c1,c2);
    if(c1!=s1){
        go("0000");
        return ;
    }
    go1(1);
    if(s2[0]!=c2[0] || s2[1]!=c2[1]){
        go("000");
        return ;
    }
    go1(1);
    if(s2[2]<='C' && c2[2]>='D'){
        go("00");
        return ;
    }
    go1(1);
    if(s2[2]+1==c2[2] || c2[2]+1==s2[2]){
        go(1);
        return ;
    }
    go1(0);
	return ;

}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	while(t--) solve();
	return 0;
}
