#include<bits/stdc++.h>
#include<queue>
#define ll long long
#define mp make_pair
#define ft first
#define sd second
#define pb push_back
#define endl "\n"
using namespace std;
const ll N=3e6+5,INF=0x3f3f3f3f3f3f3f3f;
ll n,a[N],wz[N],d;
ll f[N],g[N],ans;
void sovle(){
	for(int i=1;i<=n;i++){
		wz[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
	}
	ll su=0;ans=0;
	for(int i=1;i<=n;i++){
		if(wz[i]==i){
			f[i]=g[i]=0;
			su=i-1;
		}
		else if(wz[i]==i-1){
			f[i]=f[wz[i]];
			g[i]=0;
			if(wz[i]==wz[i+1]) g[i]+=wz[i]-su-f[wz[i]];
		}
		else{
			f[i]=f[wz[i]]+g[wz[i]];
			g[i]=i-su-max(wz[i+1],wz[i]+1);
			if(wz[i+1]==wz[i]) g[i]+=wz[i]-su-f[wz[i]]-g[wz[i]];
		}
		ans+=f[i];
//		cout<<f[i]<<" "<<g[i]<<endl;
	}
	cout<<ans<<endl;
}
namespace sub1{
	vector<ll> ww;
	void sovle(){
		ans=0;
		for(int i=1;i<=n;i++){
			ww.clear();
			ll l=i,r=i,le=1;
			while(r<=n&&l<=n){
				ll wz=upper_bound(a+1,a+1+n,a[r]+d)-a-1;
				if(wz==r){break;
				}
				if(r-l+1==1){
					if(f[r]){
						ans+=wz-r;
						for(int j=max(r+1,wz-3);j<=wz;j++) f[j]=1,ww.pb(j);
					}
				}
				else if(r-l+1==2){
					ll wz1=upper_bound(a+1,a+1+n,a[r-1]+d)-a-1;
					if(!f[r]&&!f[r-1]){
						ans+=wz1-r;
						for(int j=max(r+1,wz1-3);j<=wz1;j++) f[j]=1,ww.pb(j);
					}
					else if(f[r]){
						ans+=wz-wz1;
						for(int j=max(wz1+1,wz-3);j<=wz;j++) f[j]=1,ww.pb(j);
					}
				}
				else{
					ll wz1=upper_bound(a+1,a+1+n,a[r-1]+d)-a-1;
					ll wz2=upper_bound(a+1,a+1+n,a[r-2]+d)-a-1;
					if(!f[r]&&!f[r-1]){
						ans+=wz1-wz2;
						for(int j=max(wz2+1,wz1-3);j<=wz1;j++) f[j]=1,ww.pb(j);
					}
					else if(f[r]){
						ans+=wz-wz1;
						for(int j=max(wz1+1,wz-3);j<=wz;j++) f[j]=1,ww.pb(j);
					}
				}
				l=r+1,r=wz;
			}
			for(int i:ww) f[i]=0;
//			cout<<i<<" "<<ans<<endl;
		}
		cout<<ans<<endl;
	}
}
namespace sub2{
	void sovle(){
		for(int j=1;j<=n;j++) f[j]=g[j]=0;
		f[1]=g[1]=0;
		for(int j=2;j<=n;j++){
			ll wz=lower_bound(a+1,a+1+n,a[j]-d)-a;
			if(wz==j)break;
			f[j]=f[wz]+1,g[j]=0;
			if(f[wz]==f[wz+1]&&f[wz+2]!=f[wz+1]){
				if(!g[wz]&&!g[wz+1]) g[j]=1;
			}
			else{
				if(g[wz]) g[j]=1;
			}
		}
		ans=0;
		for(int i=1;i<=n;i++) g[i]+=g[i-1],ans+=g[i];
		cout<<ans<<endl;
	}
}
namespace sub3{
	void sovle(){
		
	}
}
namespace sub4{
	void sovle(){
		ans=0;
		for(int i=1;i<=n;i++){
			f[i]=0;
			for(int j=i+1;j<=n;j++){
				ll wz=lower_bound(a+1,a+1+n,a[j]-d)-a;
				wz=max(wz,(ll)i);
				if(wz==j)break;
				f[j]=f[wz]+1,g[j]=0;
				if(f[wz]==f[wz+1]&&f[wz+2]!=f[wz+1]){
					if(!g[wz]&&!g[wz+1]) g[j]=1;
				}
				else{
					if(g[wz]) g[j]=1;
				}
				if(g[j]) ans++;//,cout<<i<<" "<<j<<endl;
			}
		}
		cout<<ans<<endl;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,Q;
	cin>>c>>Q;
//	Q=3;
	for(int t=1;t<=Q;t++){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
//		cerr<<n<<" "<<d<<endl;
		if(c!=0&&c<=10) sub4::sovle();
		else if((c>=15&&c<=18) ) sub1::sovle();
		else if(11<=c&&c<=12) sub2::sovle();
		else if(13<=c&&c<=14) sub1::sovle();
		else sovle();
//		sovle();
	}
	return 0;
} 
