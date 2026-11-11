#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5+100;
ll m,n,a[N],sum[N];
ll st[N][50];
ll getmax(int l,int r){
	int len=r-l+1;
	return max(st[l][(int)log2(len)],st[r-(1<<((int)log2(len)))+1][(int)log2(len)]);
}
bool check(int k){
	for(int i=1;i<=n-k+1;i++){
		if(getmax(i,i+k-1)*k-(sum[i+k-1]-sum[i-1])<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		st[i][0]=a[i];
	}
	for(int j=1;j<=log2(n);j++){
		for(int i=1;i<=n-(1<<j)+1;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	int l=0,r=n,mid,ans;
	while(l<=r){//¶þ·Ö´ð°¸
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid; 
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0; 
}
