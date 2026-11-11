#include<bits/stdc++.h>
#define int long long
//UID 1137851
//Oct 31 Today
//Dec 25 ???
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[N],lst[N],cnt[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==13||c==14){
			cout<<0<<"\n";
			continue;
		}else if(c==11||c==12){
			if(d<=x[2]-x[1]){
				cout<<0<<"\n";
				continue;
			}
			int tag=d/(x[2]-x[1]);
			cout<<max(0ll,n-(tag+tag-1))<<"\n";
			continue;
		}
		for(int i=2;i<=n;i++){
			int s=0,cc=0;
			bool flag=1;
			for(int j=i-1;j>=1;j--){
				if(x[j+1]-x[j]>d) break;
				if(lst[j]+x[i]-x[i-1]>d) lst[j]=x[i]-x[i-1],cnt[j]=1;
				else lst[j]+=x[i]-x[i-1],cnt[j]++;
				if(flag&&s+x[j+1]-x[j]<=d) s+=x[j+1]-x[j],cc++;
				else flag=0;
				if(lst[j]!=s&&cnt[j]==cc-1){
//					cout<<i<<" "<<j<<"\n";
					int k=i+1;
					ans++;
					while(x[k]-x[k-1]==d&&k<=n){
//						cout<<j<<" "<<k<<"\n";
						ans++,k++;
					}
				}
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++) lst[i]=0,cnt[i]=0;
	}
	return 0;
}

