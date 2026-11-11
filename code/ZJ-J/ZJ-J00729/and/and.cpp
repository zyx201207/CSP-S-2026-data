#include<bits/stdc++.h>
using namespace std;
int n,m,x,l,ans,a[200010][32],b[200010],sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>x;l=0;
		while(x){
			a[i][l++]=x%2;
			x/=2;
		}
	}
	for(int j=30;j>=0;--j){
		ans=0;
		for(int i=1;i<=n;++i)if(!b[i]&&a[i][j])++ans;
		if(ans>=m){
			sum+=(1<<j);
			for(int i=1;i<=n;++i)if(!a[i][j])b[i]=1;
		}
	}
	cout<<sum<<"\n";
	return 0;
}
