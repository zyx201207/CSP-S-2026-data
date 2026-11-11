#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int ans;
int a[200010];
bool sum[200010][35];
bool flag[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=0;
		while(a[i]){
			sum[i][++k]=a[i]%2;
			a[i]/=2;
		}
	}
	for(int i=32;i>=1;i--){
		int k=0;
		for(int j=1;j<=n;j++){
			if(!flag[j]&&sum[j][i]==1) k++;
		}
		ans*=2;
		if(k>=m){
			ans+=1;
			for(int j=1;j<=n;j++){
				if(sum[j][i]!=1) flag[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}

