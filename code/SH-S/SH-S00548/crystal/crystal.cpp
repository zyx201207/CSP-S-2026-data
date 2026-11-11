#include <bits/stdc++.h>
using namespace std;
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define foR(i,a,b) for(int i=a;i>=b;i--)

const int maxn=5e5+6; 

int n,m,a[maxn],s[maxn];

int find(int l,int r,int n){
	if(l==r)return l;
	int mid=(l+r)/2+1;
	int sol=a[mid]*(mid-n+1)-s[mid]+s[n-1];
	if(sol>m)return find(l,mid-1,n);
	else return find(mid,r,n);
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	For(i,1,n){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	For(i,1,n){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	For(i,1,n){
		ans=max(ans,find(i,n,i)-i+1);
	}
	cout<<ans;
	return 0;
}

