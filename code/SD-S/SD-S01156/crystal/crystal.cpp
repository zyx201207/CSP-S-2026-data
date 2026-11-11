//
#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rop(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define por(i,a,b) for(int i=a;i>=b;i--)
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double ld;
using namespace std;
int n,m,a[500005],qzh[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	rep(i,1,n)
		cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n)
		qzh[i]=qzh[i-1]+a[i];
	rep(i,1,n){
		int l=1,r=i,res=0;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*mid-(qzh[i-1]-qzh[i-mid-1])<=m){
				l=mid+1;
				res=mid;
			}
			else
				r=mid-1;
		}
		ans=max(ans,res+1);
	}
	cout<<ans;
	return 0;
}
/*
15:48 100
*/

