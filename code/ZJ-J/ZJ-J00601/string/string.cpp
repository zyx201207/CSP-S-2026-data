#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,l,r,s1,s2,ans,a[200010];
char c[200010],op,res;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	l=1;r=n;s1=a[1];s2=a[n];op=c[1];res=c[n];
	while(l<=r){
		if(op!=res)ans+=min(s1,s2);
		if(s1<s2)s2-=s1,l++,s1=a[l],op=c[l];
		else if(s1>s2)s1-=s2,r--,s2=a[r],res=c[r];
		else l++,r--,s1=a[l],s2=a[r],op=c[l],res=c[r];
	}
	cout<<ans;
}
