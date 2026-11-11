//OK
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct _{
	int a;
	char c;
}a[N];
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].a>>a[i].c;
	}
	int l=1,r=n,ls=0,rs=0,ans=0;
	char lc=0,rc=0;
	while(l<r){
		if(lc==0){
			lc=a[l].c;
			ls=a[l].a;
		}
		if(rc==0){
			rc=a[r].c;
			rs=a[r].a;
		}
		if(ls>rs){
			ls-=rs;
			if(lc!=rc)ans+=rs;
			rs=0;
			rc=0;
			--r;
		}else{
			rs-=ls;
			if(lc!=rc)ans+=ls;
			ls=0;
			lc=0;
			++l;
		}
	}
	cout<<ans;
	return 0;
}