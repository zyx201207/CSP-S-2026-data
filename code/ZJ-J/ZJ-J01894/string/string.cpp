#include<bits/stdc++.h>
#define AC signed
#define AK return 0
#define int long long
using namespace std;
const string fwbs="This cpp is written by @hjcz_huls.";
const int N=2e5+10;
int a[N],st[N],ed[N],n,len,l=1,r,x=1,y,le,ri,ans;
char c[N];
AC main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n,y=n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],st[i]=len+1,len+=a[i],ed[i]=len;
	ans+=c[1]!=c[n];
	while(l+l<len){
		r=len+1-l;
		if(l==ed[x]) le=ed[++x];
		else le=ed[x];
		if(r==st[y]) ri=st[--y];
		else ri=st[y];
		if(c[x]!=c[y]) ans+=min(le-l,r-ri);
		if(le-l>r-ri) l+=r-ri,r=ri;
		else r-=le-l,l=le;
	}
	cout<<ans;
	AK;
}