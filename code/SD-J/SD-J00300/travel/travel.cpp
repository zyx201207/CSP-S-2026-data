#include<bits/stdc++.h>
#define rep(l,r,i) for(int i=l;i<=r;i++)
#define rrep(l,r,i) for(int i=l;i>=r;i--)
#define rmp(v,mp) for(auto v:mp)
using namespace std;
void fre(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
}namespace ZXY{
	int c1,s1,c2,s2; 
	char a,b;
	bool check(char c){
		return (c=='A'||c=='B'||c=='C');
	}void solve(){
		ios::sync_with_stdio(0);
		cin.tie(0);cout.tie(0);
		cin>>c1>>s1>>a>>c2>>s2>>b;
		if(c1==c2)cout<<1;
		else cout<<0;
		if(c1==c2&&s1==s2)cout<<1;
		else cout<<0;
		if(c1==c2&&s1==s2&&check(a)==check(b))cout<<1;
		else cout<<0;
		if(c1==c2&&s1==s2&&check(a)==check(b)
		&&abs(a-b)==1)cout<<1;
		else cout<<0;
	}
}
int main(){fre();ZXY::solve();}


