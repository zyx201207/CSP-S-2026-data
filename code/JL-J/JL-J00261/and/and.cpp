#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int x;
int f[35][200005],t[35];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=0;x;j++){
			f[j][i]=x%2;
			t[j]+=x%2;
			x/=2;
		}
	}int fl=-1;
	for(int i=33;i>=0;i--){
		ans*=2;
		if(fl==-1&&t[i]>=m){
			fl=i;
			ans++;
			continue;
		}if(t[i]<m) continue;
		for(int j=1;j<=n;j++){
			if(f[i][j]==1&&f[fl][j]==0){
				t[i]--;
				f[i][j]=0;
			}
		}if(t[i]>=m){
			ans++;
			fl=i;
		}
	}//for(int
	cout<<ans;
	return 0;
}
