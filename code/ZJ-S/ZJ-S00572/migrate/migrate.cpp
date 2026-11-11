#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,x[2000005],l[2000005],r[2000005],ans;
int ll[2000005],lr[2000005],rl[2000005],rr[2000005];
int ansl[2000005],ansr[2000005];
bool check(int u,int v)
{
	if(u>=v)return false;
//	if(!(u==1&&v==4))return false;//-------------------------DEBUG
//	cout<<u<<" "<<v<<"\n";
	vector<int> wl,wr;int i;
	i=u;while(r[i]<v){if(r[i]==i)return false;i=r[i];wl.push_back(i);}
	i=v;while(l[i]>u){if(l[i]==i)return false;i=l[i];wr.push_back(i);}
	sort(wr.begin(),wr.end());int L=wl.size();
	if(wr.size()!=L)return false;bool f=false;
//	cout<<u<<' '<<v<<"\n";
//	cout<<"wlwr"<<L<<"\n";
//	for(int i=0;i<L;i++)cout<<wl[i]<<" "<<wr[i]<<"\n";
//	cout<<"end.\n";
	for(int i=0;i<L;i++)
	{
		if(wl[i]==wr[i])continue;
		if(f)return false;f=true;
		if(wl[i]-wr[i]!=1)return false;
	}
//	cout<<u<<' '<<v<<" "<<f<<"\n";
	return f;
//	return true;
}
void Main()
{
	cin>>n>>d;int L,R;ans=0;
	for(int i=1;i<=n;i++)cin>>x[i];
	memset(ll,0x3f,sizeof(ll));
	memset(rl,0x3f,sizeof(rl));
	for(L=n,R=n;L>=1;L--)
	{
		while(x[R]-x[L]>d)l[R--]=L+1;
	}while(R>=1)l[R--]=1;
	for(L=1,R=1;R<=n;R++)
	{
		while(x[R]-x[L]>d)r[L++]=R-1;
	}while(L<=n)r[L++]=n;
//	for(int i=1;i<=n;i++)cout<<l[i]<<" ";cout<<"\n";
//	for(int i=1;i<=n;i++)cout<<r[i]<<" ";cout<<"\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans+=check(i,j);
//			cout<<"\n";
		}
	}
	cout<<ans<<"\n"; 
//	for(int i=1;i<=n;i++)
//	{
//		ll[l[i]]=min(ll[l[i]],i);
//		lr[l[i]]=max(lr[l[i]],i);
//		rl[r[i]]=min(rl[r[i]],i);
//		rr[r[i]]=max(rr[r[i]],i);
//	}
//	for(int i=1;i<=n;i++)
//	{
////		if(ll[i]>1e9)ll[i]=1;
////		if(rl[i]>1e9)rl[i]=n+1;
////		if(rr[i]==0)rr[i]=n;
//
////		if(ll[i]>1e9)ll[i]=n+1;
////		if(lr[i]==0)lr[i]=n;
////		if(rl[i]>1e9)rl[i]=1;
////		if(rr[i]==0)rr[i]=0;
//
//		if(ll[i]>1e9)ll[i]=-1;
//		if(lr[i]==0)lr[i]=-2;
//		if(rl[i]>1e9)rl[i]=-1;
//		if(rr[i]==0)rr[i]=-2;
//	}
////	for(int i=1;i<=n;i++){if(!lr[i])lr[i]=lr[i-1];if(!rr[i])rr[i]=rr[i-1];}
////	for(int i=n;i>=1;i--){if(ll[i]>1e9)ll[i]=ll[i+1];if(rl[i]>1e9)rl[i]=rl[i+1];}
//	for(int i=1;i<=n;i++)cout<<ll[i]<<" ";cout<<"\n";
//	for(int i=1;i<=n;i++)cout<<lr[i]<<" ";cout<<"\n";
//	for(int i=1;i<=n;i++)cout<<rl[i]<<" ";cout<<"\n";
//	for(int i=1;i<=n;i++)cout<<rr[i]<<" ";cout<<"\n";
//	for(int i=1;i<=n;i++)//以 i 为右端点唯一路径数 
//	{
//		int L=rl[i],R=rr[i];L=max(L,l[i]);if(R==i)R--;
//		cout<<rl[i]<<" "<<rr[i]<<" "<<l[i]<<"\n";
//		ansl[i]=max(R-L+1,0ll);
//		if(r[l[i]]==i)ansl[i]+=ansl[l[i]];
//	}
//	cout<<"ansl: ";for(int i=1;i<=n;i++)cout<<ansl[i]<<" ";cout<<"\n";
//	for(int i=n;i>=1;i--)//以 i 为左端点唯一路径数 
//	{
//		int L=ll[i],R=lr[i];R=min(R,r[i]);if(L==i)L++;
//		ansr[i]=max(R-L+1,0ll);
//		if(l[r[i]]==i)ansr[i]+=ansr[r[i]];
//	}
//	cout<<"ansr: ";for(int i=1;i<=n;i++)cout<<ansr[i]<<" ";cout<<"\n";
//	for(int i=1;i<=n;i++)//中心相邻
//	{
//		int LL=rl[i+1],LR=rr[i+1];LL=max(LL,l[i]);
//		int RL=ll[i],RR=lr[i];RR=min(RR,r[i+1]);
//		ans+=(LR-LL+1)*(RR-RL+1);
//		if(r[l[i]]==i+1)ans+=(RR-RL+1)*ansl[l[i]];
//		if(l[r[i+1]]==i)ans+=(LR-LL+1)*ansr[r[i+1]];
//		if(r[l[i]]==i+1&&l[r[i+1]]==i)ans+=ansl[l[i]]*ansr[r[i+1]];
//	}
//	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>c>>T;while(T--)Main();
	return 0;
}
//TLE 24pts
