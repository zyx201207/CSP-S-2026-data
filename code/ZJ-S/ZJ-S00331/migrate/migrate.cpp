//migrate 16.09
#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define ll long long
using namespace std;
const int N=2e6+5;
int __,_,n,l[N],r[N],lc[N],rc[N],ln[N],rn[N];
ll m,a[N],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>__>>_;
	while(_--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)ln[i]=rn[i]=lc[i]=rc[i]=0;
		for(int i=n,k=n;i;i--){
			k=min(k,i);
			while(k>1&&a[i]-a[k-1]<=m)k--;
			if(k==i)l[i]=-1;
			else{
				l[i]=k;
				if(k<i-1)ln[k]++;
			}
		}
		for(int i=1,k=1;i<=n;i++){
			k=max(k,i);
			while(k<n&&a[k+1]-a[i]<=m)k++;
			if(k==i)r[i]=-1;
			else{
				r[i]=k;
				if(k>i+1)rn[k]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(~r[i]&&l[r[i]]<i)lc[r[i]]++;
			if(~l[i]&&r[l[i]]>i)rc[l[i]]++;
		}
		for(int i=1;i<=n;i++)
			lc[i]+=(!~l[i]||r[l[i]]!=i?0:lc[l[i]]+1);
		for(int i=n;i;i--)
			rc[i]+=(!~r[i]||l[r[i]]!=i?0:rc[r[i]]+1);
		//for(int i=1;i<=n;i++)cout<<'$'<<ln[i]<<' '<<rn[i]<<'\n';
		ans=0;
		for(int i=1;i<=n;i++){
			if(!~r[i]||!~r[r[i]])continue;
			if(l[r[r[i]]]==r[i]-1&&l[r[i]-1]==i)
				ans+=1ll*lc[i]*rc[r[r[i]]];
		}
		//cout<<"$"<<ans<<'\n';
		for(int i=1;i<=n;i++){
			if(!~r[i]||!~r[r[i]])continue;
			if(l[r[r[i]]]==r[i]-1)ans+=rc[r[r[i]]];
		}
		//cout<<"$"<<ans<<'\n';
		for(int i=1;i<=n;i++){
			if(!~l[i]||!~l[l[i]])continue;
			if(r[l[l[i]]]==l[i]+1)ans+=lc[l[l[i]]];
		}
		//cout<<"$"<<ans<<'\n';
		for(int i=1;i<n;i++)
			ans+=1ll*ln[i]*rn[i+1];
		cout<<ans<<'\n';
	}
	return 0;
}
//16.39