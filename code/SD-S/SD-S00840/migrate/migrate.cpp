#include<bits/stdc++.h>
#define int long long

using namespace std;
//using namespace __gnu_pbds;

const int N=2e6+5;
int n,d,x[N],cnt[N],minn[N];
	int T=1,c;

void dfs(int now,int sum){
	if(now==n)return;
	if(sum>minn[now])return;
	for(int i=now+1;i<=n;i++){
		if(x[i]>x[now]+d)break;
		if(sum+1<minn[i]){
			minn[i]=sum+1;
			cnt[i]=1;
		}else if(sum+1==minn[i])
		cnt[i]++;
		dfs(i,sum+1);
	}
}
void solve(){
	cin>>n>>d;
	int delt=0,flg=1;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(i==2){
			delt=x[i]-x[i-1];
		}else if(i>2){
			if(delt!=x[i]-x[i-1]){
				flg=0;
			}
		}
	}
	if(c==11||c==12){
		if(d>=delt*2){
			int k=d/delt;
			cout<<max(n-k*2+1,0ll)<<"\n";
		}
		else{
			cout<<"0\n";
		}
		return;
	}else if(c==13||c==14){
		if(x[n]-x[1]==2*d||x[n]-x[1]<=d){
			cout<<"0\n";
		}else{
			int fs,se;
			for(int i=2;i<=n;i++){
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
					if(x[i+2]-x[1]<=d&&x[n]-x[i]<=d){
						cout<<"0\n";
						return;
					}if(x[i+1]-x[1]>d||x[n]-x[i]>d){
						cout<<"0\n";
						return;
					}
					
					fs=i;
					break;
				}
			}se=fs+1;
			int l=1,r=1,ans=0;
			while(r<=n&&l<=n){
				while(r<=n&&x[r]-x[l]<=d)r++;
				ans+=n-r+1;
			}
			cout<<ans<<"\n";
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof cnt);
		memset(minn,0x5f,sizeof minn);
		dfs(i,0);
		for(int j=i+1;j<=n;j++){
			if(cnt[j]==2){
				ans++;
//				cout<<i<<" "<<j<<"\n";
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
//	freopen("migrate3.in","r",stdin);
//	freopen("migrate3.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}



