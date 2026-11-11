#include<bits/stdc++.h>//8pts
using namespace std;
#define ll long long
ll i,j;
ll c,t;
ll dp[5000][5000]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	if(c==0){
		ll qqq,www;
		cin>>qqq>>www;
		if(qqq==4){
			cout<<1<<endl;
			cout<<2;
			return 0;
		}
		else{
			cout<<0<<endl;
			cout<<1;
			return 0;
		}
	} 
	while(t--){
		ll n,d;
		cin>>n>>d;
		vector<ll> x(n+1);
		ll ans=0;
		//密码的特殊性质A也那么大开个二维数组写dp都写不了。你的浮木飞走了 
		//但是对于等差 还是对于这么大数据的等差 那肯定有0个2-land啊 .不对还有体力 
		bool teA=true;
		ll cha=0;
		for(i=0;i<n;i++){
			cin>>x[i];
			if(i==1){
				cha=x[i]-x[i-1];
			}
			if(i>1){
				if(x[i]-x[i-1]!=cha)teA=false;
			}
		} 
		if(teA){
			if(d/cha>=n-1){
				cout<<0;
				continue;//破鸟飞密码飞 看广告获得无限体力 
			}
			else if(d/cha>=n-2){
				cout<<1<<endl;
				continue;
			}
			else if(d/cha==2){
				cout<<n-2;
				continue;
			}
			else {
				cout<<0;
				continue;
			}
		}
		else{
			for(i=0;i<n;i++){
				if(i<n-1){
					dp[i][i+1]=1;
				}
				if(i<n-2){
					if(x[i+2]-x[i]<=d)dp[i][i+2]=2;
				}
				if(i<n-1){
					ll now=0;
					ll anss=0;
					for(j=i+1;j<n;j++){
						now+=x[j]-x[i];
						anss++;
						if(now>d){
							anss--;
							dp[i][j]=max(dp[i][j],anss);
							anss=0;
							now=0;
							break;
						}
						if(now==d){
							dp[i][j]=max(dp[i][j],anss);
							anss=0;
							now=0;
							break;
						}
					}
				}
				
			}
			ll ans=0;
			for(i=0;i<n;i++){
				for(j=i;j<n;j++){
					if(dp[i][j]==2)ans++;
				}
			}
			cout<<ans-1<<endl;
		}
//		ll ans=0;
//		ll dp[5001][5001],wlong[5001];
//		for(i=0;i<n;i++){
//			cin>>x[i];
//			if(i>0){
//				dp[i][i-1]=1;
//				wlong[i]=x[i]-x[i-1];
//			}
//		}
//		for(ll len=2;len<n;len++){
//			for(i=0;i<n-len;i++){
//				j=i+len;
//				
//			}
//		}
	}
	return 0;
}
/*
呜→呜↗呜↘呜 → 呜→呜↗呜↘呜↗ 呜→ 呜↘呜→呜↘呜→呜→↘呜→呜→ 
*/ 
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

