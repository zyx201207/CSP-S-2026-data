#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e4+5;
int n,m;
int a[N];
int f[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f[i][0]=INT_MAX;
	}
	for(int i=1;i<=n;i++){
		f[i][1]=a[i];
		for(int j=1;j<=i;j++){
			for(int k=1;k<i;k++){
				f[i][j]=max(f[i][j],f[k][j-1]&a[i]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i][m]);
	}
	cout<<ans;
}
