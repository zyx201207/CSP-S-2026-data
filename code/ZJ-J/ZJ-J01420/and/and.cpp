#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,m;
int a[maxn];
int ans;
int maxa,lmaxa;
bool greed[maxn];
int dig(int x,int y){
	return (x>>y)&1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		greed[i]=1;
		maxa=max(maxa,a[i]);
	}
	for(int i=0;(maxa>>i)>0;i++)lmaxa=i;
	for(int i=lmaxa;i>=0;i--){
		int res=0;
		for(int j=1;j<=n;j++){
			if(greed[j]&&dig(a[j],i))res++;
		}
		if(res<m)ans<<=1;
		else{
			ans=(ans<<1)+1;
			for(int j=1;j<=n;j++)if(dig(a[j],i)==0)greed[j]=0;
		}
	}
	cout<<ans;
	return 0;
}