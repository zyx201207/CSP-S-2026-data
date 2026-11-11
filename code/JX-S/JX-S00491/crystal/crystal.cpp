#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,h=1,t=1,q,ans,pans;
int a[500010],x[500010],c[500010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cerr.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		x[i]=a[i]-a[i-1];
		c[i]=a[i]-a[1];
	}
	x[1]=0;/*
	for(int i=1;i<=n;i++){
		cerr<<a[i]<<' ';
	}
	cerr<<'\n';
	for(int i=1;i<=n;i++){
                cerr<<x[i]<<' ';
        }
        cerr<<'\n';
	for(int i=1;i<=n;i++){
                cerr<<c[i]<<' ';
        }
        cerr<<'\n';*/
	for(t=1;t<=n;t++){
		q+=(x[t]*(t-h));
		if(q<=m){
			ans++;
		}
		else{
			pans=max(pans,ans);
			ans++;
			while(q>m){
				q-=(c[t]-c[h]);
				h++;
				ans--;
			}
			pans=max(pans,ans);
		}
	}
	//warn!
	pans=max(pans,ans);
	cout<<pans;
	return 0;
}
