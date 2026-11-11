#include <bits/stdc++.h>
using namespace std;
template<typename TN> inline TN read(){
	TN rst=0;bool mns=0;
	char ch=getchar();
	while(ch!='-'&&!isdigit(ch))ch=getchar();
	if(ch=='-')mns=1,ch=getchar();
	while(isdigit(ch))rst=rst*10+(ch^48),ch=getchar();
	return mns?-rst:rst;
} 
int n,ans;
long long m,a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
	n=read<int>();
	m=read<long long>();
	for(int i=1;i<=n;++i)a[i]=read<long long>();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
		int l=1,r=i-1,rst=i;
		//rst~i-1 ±ä a[i]
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid)-(s[i-1]-s[mid-1])<=m)rst=mid,r=mid-1;
			else l=mid+1;
		} 
		ans=max(ans,i-rst+1);
		//cerr<<rst<<' '<<i<<'\n';
	}
	cout<<ans;
	return 0;
}
