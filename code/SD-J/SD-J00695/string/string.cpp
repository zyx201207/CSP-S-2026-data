#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c,b;
ll n,a[20000005],ans,aa[20000005],k;
int main(){//一定删注释,x1y1x2y2是个欸
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	k=ceil(n*1.0/2);
	for(ll i=1;i<=k;i++){
		c[i]=b[n-i+1];
		aa[i]=a[n-i+1];
	}
	
	for(int i=1;i<=k;i++){
		if(b[i]-'0'==c[i]-'0' && aa[i]==a[i]){continue;}
		else if(b[i]-'0'==c[i]-'0'){ans=ans+max(aa[i],a[i])-min(aa[i],a[i]);}
		else{ans=ans+max(aa[i],a[i]);}
	}
	cout<<ans;
	return 0;
}

