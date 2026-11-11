#include<bits/stdc++.h>
#define int long long
#define double long double
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int N=5e5+10;
const int L=30;
int n,m;
int a[N];
int sum[N];
int st[N][L];
int ask(int l,int r){
	int lg=__lg(r-l+1);
	return max(st[l][lg],st[r-(1<<lg)+1][lg]);
}
bool check(int l,int r){
	if(l==r)return 1;
	int mx=ask(l,r);
	return ((r-l+1)*(mx)-sum[r]+sum[l-1]<=m);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(st,-0x3f,sizeof st);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		st[i][0]=a[i];
		sum[i]=sum[i-1]+a[i];
	}
	int lg=__lg(n);
	for(int j=1;j<=lg;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		int res=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(i,mid)){
				l=mid+1;
				res=mid;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,res-i+1);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

6 2
1 3 3 3 2 1

7 10
-10 -8 -10 -6 -5 2 -2 
*/
