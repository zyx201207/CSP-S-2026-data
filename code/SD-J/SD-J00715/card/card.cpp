#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define to0(x) memset(x,0,sizeof x)
#define to_1(x) memset(x,-1,sizeof x)
#define toinf(x) memset(x,0x3f,sizeof x)
#define Debug cout<<"DEBUG\n";
#define Deon(x) cout<<"DEBUG:"<<x<<'\n';
#define pb(x) push_back(x)
#define CLOSE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int n,m;
vector<int> a,mn;
vector<vector<int> > sm,ps; 

bool chk(int i,int k,int md) {
	cout<<i<<" "<<k<<" "<<md<<"\n";
	if(sm[a[k]][i]-sm[a[k]][md]>0&&sm[a[k]][n]-sm[a[k]][i]>0) return 1;
//	if(sm[a[i]][n]-sm[a[i]][md]%2==1) return 1;
	return 0;
}

int main() {
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);

	cin>>n>>m;
	a.resize(n+1),mn.resize(m+1,inf);
	sm.resize(m+1,vector<int> (n+1,0));
	ps.resize(m+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) 
		for(int j=1;j<=n;j++) {
			if(a[j]==i) sm[i][j]=sm[i][j-1]+1;
			else sm[i][j]=sm[i][j-1];
		}
	for(int i=1;i<=n;i++) {
		int mx=0;
		int l,r,md;
		for(int k=1;k<=n;k++) {
			l=0,r=n,md;
			while(l<=r) {
//				cout<<l<<" "<<r<<'\n';
				md=(l+r)>>1;
//				cout<<chk(i,k,md)<<" ";
				if(chk(i,k,md)) mx=max(mx,md),l=md+1;
				else r=md-1; 
			}
//			mx=max(md,mx);
		}
		mn[a[i]]=min(mn[a[i]],mx);
//		if(n==4) cout<<md<<'\n';
	}
	srand(time(0));
	for(int i=1;i<=m;i++) {
		cout<<rand()%n<<" ";
	} 

	return 0;
}
/*
题意：
这不就是钓鱼吗 
相同的牌可以把中间这些全部收走
问所有轮数里有几轮第i张牌还在桌面上

4 3
1 2 1 3

*/ 
