#include <bits/stdc++.h>
using namespace std;
long long n,d;
long long x[2000005];
long long vis_num[2000005];
int short_len[2000005];
void dfs(int t,int len){
	int zz=t+1;
	len++;
	while((x[zz]-x[t])<=d&&zz<=n){
		if(len<short_len[zz]){
			short_len[zz]=len;
			vis_num[zz]=1;
		}
		else if(len==short_len[zz])vis_num[zz]++;
		else return;
		dfs(zz,len);
		zz++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i=1;i<=n;i++)cin >> x[i];
		if(n<=9){
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++)vis_num[j]=0,short_len[j]=INT_MAX;
				vis_num[i]=1;
				dfs(i,0);
				for(int j=i+1;j<=n;j++)if(vis_num[j]==2)ans++;
			}
			cout << ans << '\n';
		}
		else{
			int c=a[2]-a[1];
			bool pd=true;
			for(int i=3;i<=n;i++){
				if(a[i]-a[i-1]!=c){
					pd=false;
					break;
				}
			}
			if(pd){
				if(c>d)cout << 0 << '\n';
				else if(c>=(d+1)/2)cout << n-2;
				else cout << 0;
			}
		}
	}
	return 0;
} 
//16!
