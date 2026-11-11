#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt,ans;
int b[200010],d[200010];
char a[200010],c[200010];
signed main(){
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
	}
	d[1]=1;
	for(int i=1;i<=n;i++){
		c[i]=a[n-i+1];
		d[i+1]=d[i]+b[n-i+1];
	}
	int s=1,e=0,x=1;
	for(int i=1;i<=n;i++){
		e=s+b[i]-1;
		if(a[i]!=c[x]) ans+=min(e,d[x+1]-1)-s+1;
		while(e>=d[x+1]&&x<=n){
			if(e>=d[x+2]&&a[i]!=c[x+1]) ans+=d[x+2]-d[x+1];
			else if(a[i]!=c[x+1]) ans+=e-d[x+1]+1;
			x++;
		}
		s=e+1;
	}
	cout<<ans/2;
	return 0;
}
