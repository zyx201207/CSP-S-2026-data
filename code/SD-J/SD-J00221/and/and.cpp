#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int cnt[N];
bool k[N];
bool f[N][32];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=31;j>=0;j--){
			if((a[i]>>j)&1) f[i][j]=1;
			else f[i][j]=0;
			cnt[j]+=f[i][j];
		}
		k[i]=1;
	}
	long long ans=0;
	for(int j=31;j>=0;j--){
		if(cnt[j]<m) continue;
		int t=0;
		for(int i=1;i<=n;i++){
			if(f[i][j]&&k[i]){
				t++;
			} 
		}
		if(t>=m){
			ans+=(1ll<<j);
			for(int i=1;i<=n;i++){
				if(f[i][j]==0) k[i]=0;
			}
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
