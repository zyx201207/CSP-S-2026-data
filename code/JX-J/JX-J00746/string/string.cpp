#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define int long long
struct p{
	int s;
	char c;
}a[N];
int n,m,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		 cin>>a[i].s>>a[i].c;
		 m+=a[i].s;
	}
	m/=2;
	int l=m,r=m,lid=1,rid=n;
	int ls=0,rs=0;
	char lz,rz;
	while(l>0||r>0){
		if(ls==0){
			ls=min(a[lid].s,l);
			lz=a[lid].c;
			l-=a[lid].s;
			lid++;
		}
		if(rs==0){
			rs=min(a[rid].s,r);
			rz=a[rid].c;
			r-=a[rid].s;
			rid--;
		}
		if(ls>=rs){
			if(lz!=rz) ans+=rs;
			ls-=rs;
			rs=0;
		}
		if(ls<rs){
			if(lz!=rz) ans+=ls;
			rs-=ls;
			ls=0;
		}
	}
	cout<<ans;
	return 0;
}
