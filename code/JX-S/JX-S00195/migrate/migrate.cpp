#include<bits/stdc++.h>

#define ll long long
#define ris(x,y,z) for(ll x=y;x<z+1;++x)
#define ful(x,y,z) for(ll x=y;x>z-1;--x)
#define riso(x,y,z,a) for(ll x=y;x!=a;x=z)
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);

using namespace std;

const ll N=2e6+5;

ll c,t,n,D,x[N],ans,tot;

ll mdist(ll f,ll t){
	if(f==t)
		return 0;
	ful(i,t,f+1)
		if(x[i]-x[f]<=D)
			return mdist(i,t)+1;
	return INT_MAX;
}

void sdist(ll f,ll t,ll d,ll md){
	//cout<<f<<':'<<t<<'\n';
	if(d>md){
		//cout<<"!\n";
		return;
	}
	if(f==t){
		++tot;
		//cout<<tot<<"@\n";
		return;
	}
	//ful(i,t,f+1)
		//cout<<"acc\n";
	/*ful(i,t,f+1)*/for(ll i=t;i>=f+1;--i)
		if(x[i]-x[f]<=D)
			sdist(i,t,d+1,md);
	//cout<<"#\n";
}

signed main(){
	fre("migrate");
	ios::sync_with_stdio(0);
	cin.tie(0),
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(x,0,n*sizeof(ll));
		ans=0;
		cin>>n>>D;
		ris(i,1,n)
			cin>>x[i];
		ris(i,1,n-1)
			ris(j,i+1,n){
				ll md=mdist(i,j);
				//cout<<i<<' '<<j<<' '<<md<<":\n";
				if(md-INT_MAX>=0)
					continue;
				tot=0;
				sdist(i,j,0,md);
				//cout<<tot<<'\n';
				if(tot==2)
					++ans;
			}
		cout<<ans<<'\n';
	}
	return 0;
} 

/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
