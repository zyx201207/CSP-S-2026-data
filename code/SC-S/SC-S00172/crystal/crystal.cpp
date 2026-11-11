#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+7,M=1e4+7;
int a[N],c[N];
int n;
ll m,f[M][M],jc[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	int fl=1;
	for(int i=3;i<=n;i++){
		if(c[i]!=c[i-1]&&c[i]!=0){
			fl=0;
			break;
		}
	}
	if(fl&&n>5002){
		jc[0]=0;
		int d=c[3]-c[2];
		for(int i=1;i<=n;i++){
			jc[i]=jc[i-1]+i;
		}
		for(int i=1;i<=n;i++){
			if(jc[i]*d>m||jc[i]*d<0){
				cout<<i-1;
				return 0;
			}
		}
		
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(j==1){
				f[i][j]=0;
			}else{
				f[i][j]=f[i-1][j-1]+(a[i]-a[i-1])*(j-1);
				if(f[i][j]<=m) ans=max(ans,j);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=i;j++){
//			cout<<f[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/