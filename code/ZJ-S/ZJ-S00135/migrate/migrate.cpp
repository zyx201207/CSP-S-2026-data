#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353,inf=3e18,base=233;
int c,T,n,d,ans,a[2000005],nxt[2000005],f[2000005],mx[2000005];
vector<int>v;
void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(c>10){
		int del=a[n]-a[n-1];
		if(d>=del*3){
			cout<<0<<endl;
			return;
		}
		if(d<2*del){
			cout<<0<<endl;
			return;
		}
		cout<<n-3<<endl;
		return;
	}
	for(int i=0;i<=n;i++)nxt[i]=0,f[i]=0,mx[i]=inf;
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]>d){
			mx[i]=i;
		}
	}
	mx[n]=n;
	for(int i=n-1;i>=1;i--){
		mx[i]=min(mx[i],mx[i+1]);
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n,res=i;
		while(l<=r){
			int mid=l+r>>1;
			if(a[mid]-a[i]<=d){
				res=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		nxt[i]=res;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=mx[i];j++){
			v.clear();
			int now=i,cnt=0;
			while(now<=j){
				cnt++;
				v.push_back(now);
				now=nxt[now];
				if(now==j)break;
			}
			v.push_back(j);
			if(v.size()<=2)continue;
			int res=0,len=v.size();
			for(int k=0;k<=len-3;k++){
				if(a[v[k+2]]-a[v[k+1]-1]<=d&&a[v[k+2]]-a[v[k+1]-2]>d)res++;
			}
			if(res==1)ans++;
		}
	}
	cout<<ans<<endl;		
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)solve();
}