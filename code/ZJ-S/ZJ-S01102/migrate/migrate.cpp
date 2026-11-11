#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
const int N=2e6+5;
long long a[N];
bool v[N];
long long minn=1e18;
long long sum=0;
void dfs(int x,int ex,long long s){
//	if(sum>2)return;
	if(s>minn)return;
	if(x==ex){
		if(minn==s){
			sum++;
		}else if(minn>s){
			sum=1;
		}
		minn=min(minn,s);
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==x||v[i]||abs(a[x]-a[i])>d)continue;
		v[i]=1;
		dfs(i,ex,s+1);
		v[i]=0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>=1&&c<=6){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
//			v[1]=1;
//			dfs(1,4,0);
//			cout<<sum<<'\n';
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					sum=0;
					minn=1e18;
					memset(v,0,sizeof v);
					v[i]=1;
					dfs(i,j,0);
//					cout<<i<<' '<<j<<' '<<sum<<'\n';
					if(sum==2){
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}else if(c==0||c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			long long x=abs(a[2]-a[1]);
//			cout<<n<<' '<<d<<' '<<x<<'\n';
			long long y=d/x;
			if(y>=2&&n>=y*2){
				cout<<n-(y+y-1)<<'\n';
			}else{
				cout<<0<<'\n';
			}
		}
	}
	return 0;
}
