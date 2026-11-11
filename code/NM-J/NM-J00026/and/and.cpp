#include <bits/stdc++.h>
using namespace std;
int n,m,sum;
long long a[200005],f[50],ans,vis[200005],p[200005];
void solve(int x){
	sum=-1;
	fill(vis,vis+200003,0);
	for(int i=1;i<=n;i++){
		if((a[i]&(1<<x))&&!p[i]){
			int t=a[i],num=0;
			for(int i=1;i<=t;i=i<<1){
				if(i&t){
					vis[num]++;
				}
				num++;
			}
		}
		else{
			p[i]=1;
		}
	}
	for(int i=x-1;i>=0;i--){
		if(vis[i] >= m){
			sum=i;
			break;
		}

	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	sum=-1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		int t=a[i],num=0;
		for(int i=1;i<=t;i=i<<1){
			if(i&t){

				f[num]++;
			}
			num++;
		}
	}
	for(int i=30;i>=0;i--){
		if(f[i] >= m){
			sum=i;
			break;
		}
	}
	if(sum == -1){
		cout << 0;
		return 0;
	}
	ans+=pow(2,sum);
	while(sum>=0){
		solve(sum);
		if(sum>=0)ans+=pow(2,sum);
	}

	cout << ans << endl;
	return 0;
}
