#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,T,ans,n,d,a[2000005],h[305],cnt;
int rx(int s,int t){
	int tt=upper_bound(a+s,a+t+1,a[s]+d)-a-1;
	return tt;
}
void solve(){
	ans=0,cnt=0;
	int pd=0,flag=0;
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]-a[i-1]>d){
			h[++cnt]=i-1;
		}
	}
	pd=a[2]-a[1];
	for(int i=3;i<=n;++i){
		if(a[i]-a[i-1]!=pd){
			flag=1;
			break;
		}
	}
	if(!flag){
		if(a[2]-a[1]>=d){
			cout<<0<<endl;
			return;
		}
		d/=a[2]-a[1];
		for(int i=d+2;i<=n;++i){
			if(i%d==0&&i/d<3){
				ans+=n-i+1;
//				cout<<i<<' '<<d<<endl;
			} 
		}
		cout<<ans<<endl;
		return;
	}
	h[++cnt]=n;
	for(int w=1;w<=cnt;++w){
		for(int i=h[w-1]+1;i<=h[w];++i){
			for(int j=i+1;j<=h[w];++j){
//				if(a[j]-a[i]>2*d) break;
//				if(a[j]-a[i]<d) continue;
				int num=0;
				for(int k=i;k<j;++k){
					int r=upper_bound(a+k,a+j+1,a[k]+d)-a-1;
					if(r==k+1) continue;
					if(rx(r,j)==rx(r-1,j)&&rx(r,j)>rx(r-2,j)){
						num++;
//						if(j-i+1==4) cout<<"HHHH";
					} 
					k=r-1;
				}
				if(num==1){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
}
void solve2(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(a[2]-a[1]>=d){
		cout<<0<<endl;
		return;
	}
	d/=a[2]-a[1];
	for(int i=d+2;i<=n;++i){
		if(i%d==0&&i/d<3){
			ans+=n-i+1;
//			cout<<i<<' '<<d<<endl;
		} 
	}
	cout<<ans<<endl;
}
void solve3(){
	cin>>n>>d;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cout<<0<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		if(c==11||c==12) solve2();
		if(c==13||c==14) solve3();
		else solve();
	}
	return 0;
}