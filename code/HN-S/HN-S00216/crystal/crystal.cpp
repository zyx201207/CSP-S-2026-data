#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5;

int n;
ll m;
ll a[N];
int ans;

inline ll read(){
	char c;
	int f=1;
	ll res=0;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
		  f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res*=10;
		res+=(c-'0');
		c=getchar();
	}
	return res*f;
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
//	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    a[i]=read();
//		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int pos1=1,pos2=1;
	ll res=0;
	for(;pos2<=n;pos2++){
		res+=(pos2-pos1)*1ll*(a[pos2]-a[pos2-1]);
		while(res>m){
			res-=(a[pos2]-a[pos1]);
			pos1++;
		}
		ans=max(ans,pos2-pos1+1);
	}
	cout<<ans<<'\n';
	return 0;
}
