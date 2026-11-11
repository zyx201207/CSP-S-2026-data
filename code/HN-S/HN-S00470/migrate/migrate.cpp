#include<bits/stdc++.h>
#define lb(x) (x&-x)
#define int long long
using namespace std;
int a[2000010],nt[2000010],dp1[2000010],dp2[2000010],n,s[2000010];
void add(int x,int k){
	for(int i=x;i<=n;i+=lb(i))
		dp1[i]+=k;
}
int query(int x){
	int as=0;
	for(int i=x;i>0;i-=lb(i))
		as+=dp1[i];
	return as;
}
void MAIN()
{
	int d,as=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i],dp1[i]=0,dp2[i]=1e9,s[i]=0;
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(a[mid]-a[i]>d)
				r=mid-1;
			else
				l=mid;
		}
		if(a[r]-a[i]<=d)
			l=r;
		nt[i]=l;
		// cout<<nt[i]<<' ';
	}
	// cout<<'\n';
	/*dp2[1]=1;
	add(1,1);
	add(1+1,-1);
	int mx=0,st=0,ed=0;
	for(int j=1;j<n;j++){
		if(mx!=dp2[j]+1)
			st=n,ed=n-1;
		for(int k=nt[j];k>j;k--){
			if(dp2[k]==1e9){
				st=min(st,k);
				dp2[k]=dp2[j]+1;
				// dp1[k]+=dp1[j];
				mx=dp2[k];
				ed=nt[j];
			}
			else
				break;
		}
		int k=query(j);
		add(st,k);
		add(ed+1,-k);
		// cout<<k<<' ';
	}
	// cout<<'\n';
	for(int i=1;i<=n;i++){
		int k=query(i);
		if(k%2==0)
			as+=s[k/2];
		s[k]++;
		if(nt[i]==i)
			add(i,-k);
	}
	*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			dp2[j]=1e9,dp1[j]=0,s[j]=0;
		dp2[i]=0;
		add(i,1);
		add(i+1,-1);
		s[i]=0;
		int mx=0,st=0,ed=0;
		for(int j=i;j<n;j++){
			if(dp2[j]==1e9)
				break;
			if(mx!=dp2[j]+1)
				st=n,ed=n-1;
			for(int k=nt[j];k>j;k--){
				if(dp2[k]==1e9){
					st=min(st,k);
					dp2[k]=dp2[j]+1;
					// dp1[k]+=dp1[j];
					mx=dp2[k];
					ed=nt[j];
				}
				else
					break;
			}
			int k=query(j);
			add(st,k);
			add(ed+1,-k);
		}
		// for(int j=1;j<=i;j++)
			// cout<<query(j)<<' ';
		for(int j=i+1;j<=n;j++){
			// cout<<query(j)<<' ';
			if(query(j)==2)
				as++;
		}
		// cout<<'\n';
	}
	cout<<as<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cid,T;
	cin>>cid>>T;
	while(T--){
		MAIN();
	}
	return 0;
}
/*
考虑起点右移时最短路的变化,发现是每一段最短路相同的最后几个加上了1,
*/