#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int c,t,x[N],n,lca[N][25],l,r,mid,d,anss,now,ans,pre,fl,f[N];
int check(int xx,int yy){
	if(x[f[yy]]-x[yy-1]<=d){
		if(x[f[yy]]-x[yy-2]<=d)return 3;
		return 2;
	}
	return 1;
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
    	cin>>n>>d;
    	for(int i=1;i<=n;++i)cin>>x[i];
    	for(int i=1;i<=n;++i){
    		l=i,r=n;
    		while(l<=r){
    			mid=(l+r)>>1;
    			if(x[mid]-x[i]>d)r=mid-1;
    			else {
    				anss=mid;
    				l=mid+1;
				}
			}
			f[i]=anss;
		}
		sort(x+1,x+n+1);
		//for(int i=1;i<=n;++i)cout<<f[i]<<' ';
		for(int i=1;i<n;++i){
			now=f[i];
			pre=i;
			//cout<<i<<'\n';
			while(f[now]<=n&&now!=f[now]){
				if(check(pre,now)==1&&fl==0){
					ans+=(x[now-1]-x[pre-1]>d||(pre==i))*max((int)0,(f[now-1]-max(f[now-2],now)));
					//cout<<1<<' ';
				}
				else if(fl==0){
					//cout<<2<<' ';
					fl=1;
					if(x[now-1]-x[pre-1]>d||pre==i){
						ans+=(x[now-1]-x[pre-1]>d||(pre==i))*max((int)0,f[now-1]-max(now,f[now-2]));
					}
					else break;
					if(x[now-2]-x[pre-1]<=d)break;
				}
				else if(fl==1&&check(pre,now)==1){
					ans++;//cout<<3<<' '<<pre<<' '<<now;
				}
				else break;
				pre=now;
				now=f[now];//cout<<ans<<'\n';
			}
			fl=0;
			
		}cout<<ans<<'\n'; 
		ans=0;
	}
	
	return 0;
}
