#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+20;
int n,m;
int a[N];
int s[N];
int l;
int ans;
int Sum(int l,int r,int S){
	return 1ll*(r-l+1)*S-(s[r]-s[l-1]);
}
int get(int x){
	if(!x) return 0;
	int l=1,r=x,mid,res=-1,X=a[x+1];
	while(l<=r){
		mid=l+r>>1;
		if(Sum(mid,x,X)<=m){
			res=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	if(res==-1) return 0;
	else return x-res+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	a[n+1]=1e18,a[0]=1e18;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) l=i;
		if(a[i]!=a[i+1]){
			ans=max(ans,i-l+1+get(l-1));
		}
	}
	cout<<ans;
} 
