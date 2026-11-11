#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
int b[200005][35],f[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long x=a[i],cnt=0;
		while(x){
			b[i][++cnt]=x%2;
			x/=2;
		}
	}
	for(int i=31;i>=1;i--){
		long long x=0;
		for(int j=1;j<=n;j++){
			if(b[j][i]==1&&!f[j]) x++;
		}
		if(x>=m){
			for(int j=1;j<=n;j++){
				if(b[j][i]==0) f[j]=1;
			}
			ans+=pow(2,i-1);
		}
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/