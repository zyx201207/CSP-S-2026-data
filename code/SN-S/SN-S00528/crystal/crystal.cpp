//逆飛雨 
//琉璃色
//泫 
//雲络漫游
//雫
//这是通知 
#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cf[500006];

int ans=0;
bool cmp(int a,int b) {

	return a<b;
}
//50pts
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;cin >> n >> m;
	for(int i=0;i<n;i++) {
		cin >> a[i];

	}
	sort(a,a+n,cmp);
	for(int i=1;i<n;i++) {
		cf[i]=a[i]-a[i-1];
	}
	//for(int i=1;i<n;i++) {
	//	cout << cf[i] << ' ';
	//}
	for(int l=1;l<n;l++) {
		
			int e=0;
			for(int i=l+1;i<n;i++) {
				e+=(i-l+1)*cf[i];
				int tmp=0;
				int k=i;
				while(k<n&&a[k]==a[k+1]) {
					tmp++;k++;
					//cout << 'd';
				}
				if(e<=m)ans=max(ans,i-l+2+tmp);
			}
			//dp[l][r]=e;
			
		
	}
	//for(int i=1;i<n;i++) {
	//	for(int j=1;j<n;j++)cout << dp[i][j] << ' ';
	//	cout << '\n';
	//}
	cout << ans;
	return 0;
}
