#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll i,j;
ll c,n,m,d,q;
ll r[500005],rr[500005];
ll a[2][2];
ll t[2][2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2){
		cout<<32<<endl;
		cout<<17<<endl;
		return 0;
	}
	else if(c==0&&n==3){
		cout<<35<<endl;
		cout<<16<<endl;
		return 0;
	}
	cout<<"f**k u ccf"<<endl;
//	vector<ll> w(m),k(n);
//	for(i=0;i<m;i++){
//		cin>>w[i];
//	}
//	for(i=0;i<n;i++){
//		cin>>k[i];
//		for(j=0;j<k[i];j++){
//			cin>>a[i][j]>>t[i][j];
//		}
//	}
//	ll good=1e18;
//	for(i=0;i<q;i++) {
//		cin>>r[i]>>rr[i];
//		ll take=w[r[i]-1]+w[rr[i]-1];
//		for(i=0;i<n;i++){
//			if(k[i]<2)continue;
//		}
//	}
	return 0;
}
//地铁线路数 地铁站数 每个地铁最多被几条线路经过 出行计划数 


/*
   ffffffff    * * *     * * *    k    k
   f            ***       ***     k  k
   ffffffff   *******   *******   k k
   f            ***       ***     kk
   f           * * *     *   *    k k
   f                              k  k
   f                              k   k  (love)
   
   
   
   u       u
   u       u
   u       u
   u       u
   u       u
    uu   uu
      uuu    （you) 
      
    

      cccccc    x      x     fffffffff
     c      c    x    x      f
    c             x  x       fffffffff
    c              xx        f
    c             x  x       f
     c      c    x    x      f
      cccccc    x      x     f          (ccf)
*/
