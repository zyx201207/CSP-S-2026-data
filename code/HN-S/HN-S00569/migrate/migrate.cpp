#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int ID;
int n,d,x[N];
int dis[N],cnt[N];
int l[N];
void work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(n==1){
		cout<<"0\n";
		return;
	}
	if(ID==11||ID==12){
		int v=x[2]-x[1];
		if(v*2>d||d>=x[n]-x[1])cout<<"0\n";
		else cout<<n-(2*(d/v)-1)<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		int p=lower_bound(x+1,x+n+1,x[i]-d)-x;
		l[i]=p;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dis[j]=1e9,cnt[j]=0;
		dis[i]=0,cnt[i]=1;
		for(int j=i+1;j<=n;j++){
			dis[j]=dis[max(i,l[j])]+1;
			cnt[j]=cnt[max(i,l[j])];
			for(int p=max(i,l[j])+1;p<j;p++){
				if(dis[p]+1>dis[j])break;
				cnt[j]+=cnt[p];
				if(cnt[j]>2){
					cnt[j]=3;
					break;
				}
			}
			ans+=(cnt[j]==2);
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;cin>>ID>>t;
	// t=1;
	while(t--)work();
	return 0;
}
/*
我真的服了，为什么猜结论猜了一半对的一半错的啊不是

RiverBird208 要退役了（

这辈子进不了 WinterCamp 了（
3.5h 做不出来 C 说是
*/