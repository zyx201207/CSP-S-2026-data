#include<bits/stdc++.h>
using namespace std;
#define F(i,s,e) for(int i=s;i<=e;i++)

const int N = 2e5+10;
char c[N];long long x[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	F(i,1,n)cin>>x[i]>>c[i];
	long long l=1,r=n,lr=x[1],rr=x[n],ans=0;
	while(l<r){
		int t=min(lr,rr); 
		if(c[l]!=c[r]) ans+=t;
		lr-=t;rr-=t;
//		cout<<l<<' '<<lr<<'\n'<<r<<' '<<rr<<'\n'<<ans<<'\n';
		if(!lr) l++,lr=x[l];
		if(!rr) r--,rr=x[r];
	}
	cout<<ans;
	return 0;
}


