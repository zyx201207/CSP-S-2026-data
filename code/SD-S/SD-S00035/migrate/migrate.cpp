#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+7;
int c,T,n,lst[maxn],f[5006][5006],g[5006][5006];
ll a[maxn],d,ans;
void solven2(){
	for(int i = 1;i<=n;i++){
		f[i][i]=0;
		for(int j = i+1;j<=n;j++){
			if(lst[j]==j)f[i][j]=-1;
			else if(f[i][max(i,lst[j])]==-1)f[i][j]=-1;
			else f[i][j]=f[i][max(i,lst[j])]+1;
		}
	}
	for(int i = 1;i<=n;i++){
		int r = i,cnt = 1,ls = i;
		g[i][i]=1;
		for(int j = i+1;j<=n;j++){
			if(f[i][j]==-1)break;
			for(;ls<lst[j];ls++)cnt-=g[i][ls];
			while(f[i][r+1]==f[i][j]-1){
				cnt+=g[i][r+1];
				r++;
			}
			g[i][j]=cnt;
			ans+=(cnt==2);
		}
	}
	cout << ans << "\n"; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		ans=0;
		cin >> n >> d;
		for(int i = 1;i<=n;i++)cin >> a[i];
		for(int l = 1,i = 1;i<=n;i++){
			while(a[i]-a[l]>d)l++;
			lst[i]=l;
		}
		solven2();
	}
	return 0;
}

