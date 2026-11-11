#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[502][101001],t[502][101001],w[501002];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++)cin>>a[i][j]>>t[i][j];
	}
	for(int i=0;i<q;i++){
		int sa,en;
		cin>>sa>>en;
		if(n==1){
			int r,o;
			for(int i=0;i<a[1][0];i++){
				if(a[1][i]==sa)r=i;
				if(a[1][i]==en)o=i;
			}
			int ans=0;
			ans+=w[en]+w[sa]+t[1][r]+t[1][o];
			cout<<ans;
			return 0;
		}
		if(n==2){
			int r1,o1;
		for(int i=0;i<a[1][0];i++){
			if(a[1][i]==sa)r1=i;
			if(a[1][i]==en)o1=i;
		}
		int r2,o2;
		for(int i=0;i<a[2][0];i++){
			if(a[2][i]==sa)r2=i;
			if(a[2][i]==en)o2=i;
		}
		int ans=0;
		ans+=w[en]+w[sa]+min(t[1][r1]+t[1][o1],t[2][r2]+t[2][o2]);
		cout<<ans;
		return 0;
	}
}
	return 0;
}
