#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5,M=5005;
const int inf=0x3f3f3f3f;
int C,T,n;
ll x[N],d;
int f[N],cnt[N],ll[N],rr[N];
void solve1(){//n^2
	int ans=0;
	for(int i=1;i<=n;i++){
		f[i]=0,cnt[i]=1;
		for(int j=i+1;j<=n;j++)
			cnt[j]=0,f[j]=inf;
		for(int j=i+1,l=i;j<=n;j++){
			while(l<j&&x[j]-x[l]>d)l++;
			if(l==j)break;
			f[j]=f[l]+1;
			for(int r=l;r<j;r++){
				if(f[l]!=f[r])break;
				cnt[j]+=cnt[r];
				if(cnt[j]>2)break;
			}
			if(cnt[j]==0)break;
		}
		for(int j=i+1;j<=n;j++)
			if(cnt[j]==2)ans++;
	}
	cout<<ans<<'\n';
}
void solve2(){
	int ans=0;
	ll delta=x[2]-x[1];
	if(d<=delta){cout<<"0\n";return;}
	ll t=d/delta;
	ans=max(n-t-t+1,0ll);
	cout<<ans<<'\n';
}
void solve3(){//不保证正确 
	int ans=0;
	for(int i=1,j=i;i<=n;i++){
		while(j<n&&a[j+1]-a[i]<=d)j++;
		rr[i]=j;
	}
	for(int i=n,j=i;i>=1;i--){
		while(j>0&&a[i]-a[j-1]<=d)j--;
		ll[i]=j;
	}
	for(int i=1,j=1;i<=n;i++)
		while(j<=n&&rr[i]==ll[j]+1)
			ans++,j++;
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(C<=10||n<=5000)solve2();
		else if(11<=C&&C<=12)solve2();
		else if(13<=C&&C<=14)solve3();
		else solve1();
	}
	return 0;
}
/*
16:52 40pts
17:25 48pts
*/
