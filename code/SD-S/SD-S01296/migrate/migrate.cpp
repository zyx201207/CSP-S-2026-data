#include <iostream>
#include <cmath>
#define int long long
#define N 2000005
using namespace std;
int a[N],pre[N][23],nxt[N][23],pr[N][23],nt[N][23],num;
int get_pre(int l,int r){
	if (pre[r][22]>l)  return -1;
	int ans=0,pos=r,i,j,k;
	for (i=22;i>=0;i--){
		if (pre[pos][i]>l){
			ans+=pr[pos][i];pos=pre[pos][i];
		}
	}
	ans+=pr[pos][0];ans+=l;
	return ans;
}
int get_nxt(int l,int r){
	if (nxt[l][22]<r)  return -1;
	int ans=0,pos=l,i,j,k;
	for (i=22;i>=0;i--){
		if (nxt[pos][i]<r){
			ans+=nt[pos][i];pos=nxt[pos][i];
		}
	}
	ans+=nt[pos][0];ans+=r;
	return ans;
}
void solve(){
	int i,j,k,n,d,m;
	cin>>n>>d;
	for (i=1;i<=n;i++)  cin>>a[i];
		j=1;
		for (i=1;i<=n;i++){
			while (a[i]-a[j]>d)  j++;
			pre[i][0]=j;pr[i][0]=i;
		}
		j=n;
		for (i=n;i>=1;i--){
			while (a[j]-a[i]>d)  j--;
			nxt[i][0]=j;nt[i][0]=i;
		}
		for (i=1;i<=22;i++){
			for (j=1;j<=n;j++)  pre[j][i]=pre[pre[j][i-1]][i-1];
			for (j=1;j<=n;j++)  nxt[j][i]=nxt[nxt[j][i-1]][i-1];
			for (j=1;j<=n;j++)  pr[j][i]=pr[j][i-1]+pr[pre[j][i-1]][i-1];
			for (j=1;j<=n;j++)  nt[j][i]=nt[j][i-1]+nt[nxt[j][i-1]][i-1];
		}
		int ans=0;
		for (i=1;i<=n;i++){
			for (j=1;j<i;j++){
				if (get_nxt(j,i)-get_pre(j,i)==1)  ans++;
			}
		}
		cout<<ans<<'\n';
}
signed main()
{
	cin.tie(0);ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;cin>>num;cin>>t;
	while (t--)  solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
#include <iostream>
#include <cstring>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define N 2000005
using namespace std;
int a[N],pre[N],nxt[N],pr[N],nt[N],mnp[N],mxp[N],mnn[N],mxn[N];
void solve(){
	int i,j,k,n,d,m;cin>>n>>d;
	for (i=1;i<=n;i++){
		mnp[i]=inf;mnn[i]=inf;mxp[i]=0;mxn[i]=0;pr[i]=0;nt[i]=0;
	}
	for (i=1;i<=n;i++)  cin>>a[i];
	j=1;
	for (i=1;i<=n;i++){
		while (a[i]-a[j]>d)  j++;pre[i]=j;
		if (pre[i]==i)  continue;
		mnp[j]=min(mnp[j],i);mxp[j]=max(mxp[j],i);
	}
	j=n;
	for (i=n;i>=1;i--){
		while (a[j]-a[i]>d)  j--;nxt[i]=j;
		if (nxt[i]==i)  continue;
		mnn[j]=min(mnn[j],i);mxn[j]=max(mxn[j],i);
	}
	for (i=1;i<=n;i++){
		if (pre[i]==i)  continue;
		int l=pre[i],r=i-1,l1=r+1,l2=r+1;
		while (l<=r){
			int mid=(l+r)/2;
			if (nxt[mid]>=i)  l1=mid,r=mid-1;
			else  l=mid+1;
		}
		l=pre[i];r=i-1;
		while (l<=r){
			int mid=(l+r)/2;
			if (nxt[mid]>i)  l2=mid,r=mid-1;
			else  l=mid+1;
		}
		pr[i]=l2-l1;
	}
	for (i=1;i<=n;i++){
		if (nxt[i]==i)  continue;
		int l=i+1,r=nxt[i],l1=l-1,l2=l-1;
		while (l<=r){
			int mid=(l+r)/2;
			if (pre[mid]<i)  l1=mid,l=mid+1;
			else  r=mid-1;
		}
		l=i+1;r=nxt[i];
		while (l<=r){
			int mid=(l+r)/2;
			if (pre[mid]<=i)  l2=mid,l=mid+1;
			else  r=mid-1;
		}
		nt[i]=l2-l1;
	}
	for (i=1;i<=n;i++)  cout<<pre[i]<<' ';cout<<'\n';
	for (i=1;i<=n;i++)  cout<<nxt[i]<<' ';cout<<'\n';
	for (i=1;i<=n;i++)  cout<<pr[i]<<' ';cout<<'\n';
	for (i=1;i<=n;i++)  cout<<nt[i]<<' ';cout<<'\n';
	for (i=1;i<=n;i++)  if (pre[i]!=i)  pr[i]+=pr[pre[i]];	//pre出去 
	for (i=n;i>=1;i--)  if (nxt[i]!=i)  nt[i]+=nt[nxt[i]];	//nxt出去 
	for (i=1;i<=n;i++)  cout<<pr[i]<<' ';cout<<'\n';
	for (i=1;i<=n;i++)  cout<<nt[i]<<' ';cout<<'\n';
	int ans=0;
	for (i=1;i<n;i++){
		if (mnp[i]==inf||mnn[i+1]==inf)  continue;
		if (pre[i+1]==i+1||nxt[i]==i||mnn[i+1]==i||mxp[i]==i+1)  continue;
		int lsum=max(mxn[i+1],pre[i])-max(mnn[i+1],pre[i])+1+pr[max(mnn[i+1],pre[i])];
		int rsum=min(mxp[i],nxt[i+1])-min(mnp[i],nxt[i+1])+1+nt[min(mxp[i],nxt[i+1])];
		cout<<i<<' '<<lsum<<' '<<rsum<<'\n';
		ans+=lsum*rsum;
	}
	cout<<ans<<'\n';
}
signed main()
{
//	freopen("migrate3.in","r",stdin);
	int t;cin>>t;cin>>t;
	while (t--)  solve();
	return 0;
}
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
6 3
0 1 2 3 4 7

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/
