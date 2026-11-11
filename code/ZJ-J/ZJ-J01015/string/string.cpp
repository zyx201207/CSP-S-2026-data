#include <bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
int a[200010];
char c[200010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=1,li=1,ri=n;
	while(li<ri){
		int tl=a[li]-l+1;
		int tr=a[ri]-r+1;
		if(c[li]!=c[ri]) ans+=min(tl,tr);
		if(tl<tr) li++,l=1,r+=tl;
		if(tl>tr) ri--,r=1,l+=tr;
		if(tl==tr) li++,ri--,l=r=1;
	}
	cout<<ans;
	return 0;
}
