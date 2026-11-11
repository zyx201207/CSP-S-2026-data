#include<bits/stdc++.h>
#define ll long long
#define int long long
#define N 500050
#define M 300050
#define rep(a,b,c) for(int a=(b);a<=(c);a++)
using namespace std;
ll n,m,a[N],lt[N],nt[N],ans[N],fa[N],num[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		nt[i]=lt[a[i]];
		lt[a[i]]=i;
		fa[i]=i;
//		cout<<i<<' '<<nt[i]<<endl;
	}
	for(int i=n;i>=1;i--){
		if(nt[i]){
			fa[i]=fa[nt[i]];
			num[fa[i]]++;
		}else{
			num[i]++;
		}
	}
	ll sum=0;
	for(int i=1;i<=n;i++){
		if(!num[i])continue;
		ans[a[i]]+=num[i];
		num[fa[i+1]]+=num[i];
	}
	for(int i=1;i<=m-1;i++){
		cout<<ans[i]<<' ';
	}
	cout<<ans[m];
	return 0;
} 
//Trick||Treat!
