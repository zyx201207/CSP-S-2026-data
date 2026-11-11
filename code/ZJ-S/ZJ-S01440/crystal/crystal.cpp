#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],n,m,sum=0,ans=-1;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,[](int p,int q){return p<q;});
	for(int l=1,r=0;l<=n;l++){
		while(r<=n){
			if(r>=l&&a[r]>(m+sum)/(r-l+1)+1||a[r]*(r-l+1)-sum>m)break;
			sum+=a[++r];
		}
		ans=max(ans,r-l);
		sum-=a[l];
	}
	cout<<ans;
	return 0;
}
