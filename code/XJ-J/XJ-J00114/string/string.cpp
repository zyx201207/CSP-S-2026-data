#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,L,ans;
struct w{
	int a;
	char c;
}s[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].c,L+=s[i].a;
	int cl=1,cr=n,al=s[1].a,ar=s[n].a;
	for(int l=1,r=L;l<=r&&l<=L&&r>=1;){
		if(s[cl].c!=s[cr].c) ans+=min(al,ar);
		if(al<ar){
			l+=al,r-=al;
			ar-=al,al=s[++cl].a;
		}
		else if(al>ar){
			l+=ar,r-=ar;
			al-=ar,ar=s[--cr].a;
		}
		else{
			l+=al,r-=ar;
			al=s[++cl].a,ar=s[--cr].a;
		}
	}
	cout<<ans;
	return 0;
}
