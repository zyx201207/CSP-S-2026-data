#include<bits/stdc++.h>

using namespace std;

#define int long long

mt19937_64 rdm(time(0));

const int N=5e3+5,inf=1e18;

int a[N],dis[N][N],f[N][N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,ans=0;
	cin>>c>>t;
	if(c==11||c==12){
		int tmp,k;
		for(int i=1;i<=t;i++){
			cin>>n>>d;
			for(int j=1;j<=n;j++){
				cin>>a[j];
			}
			tmp=a[2]-a[1];
			k=d/tmp;
//			cout<<n<<' '<<tmp<<' '<<k<<'\n';
			if(k<=1||k>=n){
				cout<<"0\n";
			}
			else if(n>=2*k){
				int sum=(k-1)*(n-2*k)+(k-1)*k/2;
				sum/=k-1;
				cout<<sum<<'\n';
			}
			else{
				int sum=(n-k-2)*(n-k-1)/2;
				sum/=k-1;
				cout<<sum<<'\n';
			}
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int now=i;
			while(now<n){
				dis[i][now+1]++;
				int l=now,r=n;
				int mid,sum=now;
				while(l<=r){
					mid=l+r>>1;
					if(a[mid]-a[i]<=d){
						sum=mid;
						l=mid+1;
					}
					else r=mid-1; 
				}
				if(sum==now){
					dis[i][now+1]=inf;
					break;
				}
				now=sum;
			}
			for(int j=i;j<=n;j++){
				dis[i][j]+=dis[i][j-1];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=0,sum=inf;
				if(dis[i][j]==1) continue;
				for(int k=i+1;k<=j-1;k++){
					if(sum==dis[i][k]+dis[k][j]){
						cnt++;
					} 
					else if(sum>dis[i][k]+dis[k][j]){
						sum=dis[i][k]+dis[k][j];
						cnt=1;
					}
				}
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

