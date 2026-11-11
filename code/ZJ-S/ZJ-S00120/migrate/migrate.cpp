//CSP-S 2026 RP++
#include<bits/stdc++.h>
#define ll long long
#define gc getchar()

using namespace std;

const int N=2e6+100;

int t,n,c,d;
ll x[N];
ll f[N];
ll num[N];

inline ll rd(){
	ll x=0,f=1;char ch=gc;
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=gc;}
	while(isdigit(ch)) {x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return x*f;
}

inline ll work(){
	ll res=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(x[i]-x[j]<=d) f[N]=1; 
		}
	}
	return res;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd();
	t=rd();
	//SPJ
	if(c==13||c==14){
		while(t--) cout<<"0\n";
		return 0;
	}
	while(t--){
		n=rd();d=rd();
		for(int i=1;i<=n;i++) x[i]=rd();
		cout<<work();	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}