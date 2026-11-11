#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long q[N];
int hh=1,tt=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,m;
		cin>>n>>m;
		hh=1,tt=0;
		long long cs=0;
		int id=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			long long x;
			cin>>x;
			long long l=0;
			if(hh<=tt&&x-q[hh]>m){
				ans+=cs;
				cs=0;
			}
			else ans+=cs;
			while(hh<=tt&&x-q[hh]>m){
				hh++,l++;
			}
			if(tt-hh+1==2&&l){
				id=tt;
				cs=l;
			}
			q[++tt]=x;
		}
		if(cs)ans+=cs*(tt-id);
		cout<<ans<<endl;
	}
	return 0;
} 
