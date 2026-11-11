#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,m;
long long a[N],ans;
bool bo[N][40],c[N],res[40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long num=a[i];
		for(int j=0;j<=32;j++){
			if(num&1) bo[i][j]=1;
			num>>=1;
		}
	}
	for(int i=32;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(c[j]==1) continue;
			if(bo[j][i]==1) cnt++;
		}
		if(cnt<m) continue;
		for(int j=1;j<=n;j++){
			if(bo[j][i]==0) c[j]=1;
		}
		res[i]=1;
	}
	for(int i=32;i>=0;i--){
		ans<<=1;
		if(res[i]==1) ans++;
	}
	cout<<ans;
	return 0;
}
