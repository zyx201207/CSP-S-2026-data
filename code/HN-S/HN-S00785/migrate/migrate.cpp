#include<bits/stdc++.h>
using namespace std;
int n,cnt[2000005],l[2000005],r[2000005],dp[2000005];
long long d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;cin>>c>>T;
	while(T--){
		cin>>n>>d;l[0]=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			l[i]=l[i-1];
			while(x[i]-x[l[i]]>d)l[i]++;
		}r[n+1]=n;
		for(int i=n;i>=1;i--){
			r[i]=r[i+1];
			while(x[r[i]]-x[i]>d)r[i]--;
		}
		//for(int i=1;i<=n;i++)cout<<l[i]<<' '<<x[i]-x[l[i]]<<'\n';cout<<'\n';
		bool tmp=1;int ml=0;
		for(int i=2;i<n;i++){
			if(x[i+1]-x[i]!=x[i]-x[i-1])tmp=0;
			if(l[i]==1&&r[i]==n&&!ml)ml=i;
		}
		if(x[n]-x[1]<=d){cout<<"0\n";}
		/*
		else if(ml){
			int mr=0;
			for(int i=n-1;i>=1;i--){
				if(l[i]==1&&r[i]==n){
					mr=i;break;
				}
			}
			if(mr-ml+1>2)cout<<"0\n";
			else if(mr-ml+1>1){
					long long ans=0;
				for(int s=1;s<ml;s++){
					if(r[s]==mr){
						ans+=n-r[ml-1];
					}
				}
				cout<<ans<<'\n';
			}else{
				long long ans=0;
				if(ml>2)ans+=(l[ml+1]-1)*(n-r[ml-2]);
				if(ml<n-1)ans+=(l[ml+2]-1)*(n-r[ml-1]);
				cout<<ans<<'\n';
			}
		}
		*/
		else if(tmp){
			long long cha=x[2]-x[1],w=d/cha;
			if(w>1)cout<<max(0ll,n-w-w+1)<<'\n';
			else cout<<"0\n";
		}else{
		//for(int i=1;i<=n;i++)cout<<x[i]+1000000000000000000<<' ';cout<<'\n';
			long long ans=0;
			for(int s=1;s<=n;s++){
				dp[s]=0;cnt[s]=1;
				r[s]=s;cnt[s-1]=0;
				for(int t=s+1;t<=n;t++){
					if(x[t]-x[t-1]>d)break;
					dp[t]=dp[max(s,l[t])]+1;
					r[t]=max(l[t],r[t-1]);
					while(r[t]<t&&dp[r[t]+1]+1==dp[t])r[t]++;
					cnt[t]=cnt[t-1]+min(cnt[r[t]]-cnt[l[t]-1],3);
					if(cnt[t]-cnt[t-1]==2)ans++;
					//printf("%d->%d,l=%d,r=%d,cnt=%d\n",s,t,l[t],r[t],cnt[t]);
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
