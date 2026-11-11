#include <bits/stdc++.h>
using namespace std;
int a[200010][35];
int ca[200010];
int ta[40];
bool vt[200010];
bool vis[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int mw = 0;
	for(int i = 1;i<=n;i++){
		int x;
		cin>>x;
		ca[i] = x;
		int tx = x;
		int cnt = 0;
		memset(ta,0,sizeof(ta));
		while(tx){
			int p = tx%2;
			ta[++cnt] = p;
			tx /= 2;
		}
		mw = max(mw,cnt);
		for(int j = 30;j>=1;j--){
			a[i][j] = ta[30-j+1];
		}	
	}
	long long sum = 0;
	int mn = n;
	for(int j = 30-mw+1;j<=30;j++){
		int cnt = 0;
		memset(vt,0,sizeof(vt));
		for(int i = 1;i<=n;i++){
			if(vis[i] == 0){
				if(a[i][j] == 0){
					cnt++;
					vt[i] = 1;
				}
			}
		}
		cnt = mn-cnt;
		int gf = 0;
		if(cnt == m){
			
			for(int i = 1;i<=n;i++){
				if(vis[i] == 0&&vt[i] == 0){
					if(gf == 0){
						sum = ca[i];
						gf = 1;
					}else{
						sum = sum&ca[i];
					}
				}
			}
			cout<<sum;
			return 0;
		}
		if(cnt>m){
			sum += pow(2,(30-j));
			for(int i = 1;i<=n;i++){
				if(vis[i] == 0){
					vis[i] = vt[i];
				}
			}
			mn = cnt;
		}
	
		
	}
	cout<<sum;
	return 0;
}