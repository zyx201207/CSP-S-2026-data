// menkeming fuluzhongxue SN-J00662
#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],lid,rid,l,r,ans;
char c[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
	}
	lid=1,rid=n;
	while(lid<rid)
	{
		if(l==0) l=1;
		if(r==0) r=a[rid];
		long long dl=a[lid]-l+1,dr=r;
		if(dl>dr){
			if(c[lid]!=c[rid]) ans+=dr;
			rid--;
			l+=dr;
			r=0;
		}
		if(dl<dr){
			if(c[lid]!=c[rid]) ans+=dl;
			lid++;
			r-=dl;
			l=0;
		}
		if(dl==dr){
			if(c[lid]!=c[rid]) ans+=dr;
			rid--;
			lid++;
			l=r=0;
		}
//		cerr<<lid<<" "<<rid<<"\n";
	} 
	cout<<ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
