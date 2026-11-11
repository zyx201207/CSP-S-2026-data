#include<bits/stdc++.h>
#define ll long long
#define F(l,r,i) for(int i=l;i<=r;i++)
#define Fa(l,r,i) for(int i=r;i>=l;i--)
using namespace std;
ll n,a[200010],ans,nowl,nowr;
char c[200010];
bool flagl=1,flagr=1;
signed main(){
	//freopen("string5.in","r",stdin);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	F(1,n,i) cin>>a[i]>>c[i];
	for(ll l=1,r=n;l<r;){
		if(flagl) nowl=a[l],flagl=0;
		if(flagr) nowr=a[r],flagr=0;
		if(c[l]==c[r]){
			if(nowl==nowr) l++,r--,flagl=flagr=1;
			else if(nowl>nowr) r--,flagr=1,nowl-=nowr;
			else if(nowl<nowr) l++,flagl=1,nowr-=nowl;
		}
		else{
			if(nowl==nowr) ans+=nowl,l++,r--,flagl=flagr=1;
			else if(nowl>nowr) ans+=nowr,r--,nowl-=nowr,flagr=1;
			else if(nowl<nowr) ans+=nowl,l++,nowr-=nowl,flagl=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
