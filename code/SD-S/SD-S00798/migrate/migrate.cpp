#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n;
ll a[2000005],d;
int dis(int x,int y){
	if(x<=0||y<=0)return -1;
	int i=x,l=0,f=-1;
	while(i<y){
		if(f==i)return -1;
		f=i,l++;
		while(i+1<=y&&d>=a[i+1]-a[f])i++;
//		cout<<(i+1<=y)<<" "<<(d>=a[i+1]-a[f])<<" "<<f<<" "<<i<<'\n';
	}
	return l;
}
bool hf(int x,int y){
	int i=x,l=0,f=-1;
	while(i<y){
		if(f==i)return 0;
		f=i;
		while(i+1<=y&&d>=a[i+1]-a[f])i++;
		int mi=dis(i,y);
		int mi1=dis(i-1,y);
		int mi2=dis(i-2,y);
		if(mi1==mi){
			if(l==1){
//				cout<<"!"<<x<<" "<<y<<" "<<i<<"\n";
				return 0;
			}
			l++;
		}
		if(mi2==mi){
//			cout<<"@"<<x<<" "<<y<<" "<<i<<" "<<mi<<" "<<mi2<<"\n";
			return 0;
		}
	}
	if(l==1)return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ll ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12){
			ll dd=d/(a[2]-a[1]);
			if(dd>1)for(int i=1;i<=n;i++)if(dd*2-1+i<=n)ans++;
		}
//		cout<<d<<" "<<dis(1,2)<<"\n";
		else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(hf(i,j))ans++;
				}
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++)a[i]=0;
	}
	return 0;
}
