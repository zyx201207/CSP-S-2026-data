//85pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int ans;
struct node{
	int a,cnt;	
}a[200005],na[200005];
bool cmp(node u,node v){
	if(u.cnt == v.cnt) return u.a > v.a;
	return u.cnt > v.cnt;	
}
int cnt[4];
int f[2005][2005];
int andf[200005][20];
void dfs(int now,int cnt,int sum){
	if(cnt == m){
		ans = max(ans,sum);
		return;
	}
	if(now == n+1) return; 
	dfs(now+1,cnt+1,sum&a[now].a);
	dfs(now+1,cnt,sum);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int maxn = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i].a;
		maxn = max(maxn,a[i].a);
		if(a[i].a < 4) cnt[a[i].a]++;
		int x = a[i].a;
		while(x){
			a[i].cnt += x&1;
			x >>= 1;
		}
	}
	if(n <= 10){
		dfs(1,0,(1 << 29)-1);
		cout << ans;
	}else if(n <= 2000){
		ans = 0;
		if(n == m){
			ans = a[1].a;
			for(int i = 1;i <= n;i++) ans &= a[i].a;
			cout << ans;
			return 0;
		}
		if(m == 1){
			cout << maxn;
			return 0;
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j) continue;
				ans = max(ans,a[i].a&a[j].a);
			}
		}
		cout << ans;
		return 0;
	}else if(maxn < 4){
		if(cnt[3] >= m) cout << 3;
		else if(cnt[3]+cnt[2] >= m) cout << 2;
		else if(cnt[3]+cnt[1] >= m) cout << 1;
		else cout << 0;
	}else{
		sort(a+1,a+1+n,cmp);
		ans = a[1].a;
		int now = 1;
		for(int i = 2;i <= n;i++){
			int val = 0;
			int pow = 1,x = a[i].a,y = ans,xnow,ynow;
			while(x){
				xnow = x&1,ynow == y&1;
				if(xnow&&ynow) val += pow*2;
				else if(!ynow) val += pow;
				x >>= 1;y >>= 1;
				pow *= 3;
			}
			na[++now] = {a[i].a,val};
		}
		sort(na+1,na+1+now,cmp);
		for(int i = 1;i < m;i++) ans &= na[i].a;
		cout << ans;
	}
} 
	
