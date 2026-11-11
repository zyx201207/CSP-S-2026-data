#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],d[200005],k,x,y,t,s;
char c[200005],b[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){d[i]=a[n-i+1];b[i]=c[n-i+1];}
	t=a[1];s=d[1];x=1;y=1;
	if(b[1]!=c[1]) k+=min(t,s);
	while(x<=n && y<=n){
		x++;y++;
		if(t>s){
			x--;
			if(c[x]!=b[y]) k+=min(d[y],t-s);
			s+=d[y];
		}
		else if(t<s){
			y--;
			if(c[x]!=b[y]) k+=min(a[x],s-t);
			t+=a[x];
		}
		else{
			s+=d[y];t+=a[x];
			if(c[x]!=b[y]) k+=min(a[x],d[y]);
		}
	}
	cout<<k/2;
	return 0;
}
