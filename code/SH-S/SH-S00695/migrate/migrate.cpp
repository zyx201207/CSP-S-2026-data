#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+6;
int c,t,n,d,a[N]; 
vector<int> b,e;
void solvea(){//特殊性质A，期望得分 8pts 
	int dx=a[2]-a[1];
	if (d<2*dx){
		cout << 0 << endl;
		return;
	}
	cout << max(0ll,n-d/dx*2+1) << endl; 
}
void solveb(){//特殊性质B，期望得分 8pts（伪了） 
	int l=a[n]-d;
	int r=a[1]+d;
	int cnt=0;
	for (int i=1;i<=n;i++) cnt+=(a[i]>=l && a[i]<=r);
	cout << (cnt==2?1:0) << endl;
}
bool check(int l,int r){
	int cnt=0,p=l;
	while(p<r){
		int L=p;
		while(a[p+1]-a[L]<=d && p<r) p++;
		if (L==p) return 0;
		if (p==r) break;
		for (int i=L+1;i<p;i++){
			cnt+=(a[p+1]-a[i]<=d && (p+2>r || a[p+2]-a[p]>d));
		}
	}
	return cnt==1;
}
void dfs(int l,int r){
	if (l==r){
		b.push_back(e.size());
		return;
	}
	for (int i=l+1;i<=r;i++){
		if (a[i]-a[l]<=d){
			e.push_back(i);
			dfs(i,r);
			e.pop_back();
		}
		else break;
	}
}
void solve12(){//n<=9暴力，期望得分 8pts 
	int ans=0;
	for (int i=1;i<=n;i++){
		for (int j=i+3;j<=n;j++){
			int flag=1;
			for (int o=i+1;o<=j;o++){
				if (a[o]-a[o-1]>d){
					flag=0;
					break;
				}
			}
			if (flag==0) break;
			b.clear();
			dfs(i,j);
			sort(b.begin(),b.end());
			int minn=b[0],p=0;
			while(minn==b[p]) p++; 
			ans+=(p==2);
//			if (p==2) cout << i << " " << j << endl;
		}
	}
	cout << ans << endl;
}
void solve(){
	int ans=0;
	for (int i=1;i<=n;i++){
		for (int j=i+3;j<=n;j++){
			ans+=check(i,j);
//			if (check(i,j)) cout << i << " " << j << endl;
		} 
	}
	cout << ans << endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for (int i=1;i<=n;i++) cin >> a[i];
		if (n<=3){
			cout << 0 << endl;
			continue;
		}
		if (n<=9) solve12();
		else if (c==11 || c==12) solvea();
		else if (c==13 || c==14) solveb();
		else solve();
	}
	
	return 0;
} 
/*
16:20 开T3
16:24 题意比T2好理解，考虑前 14 个测试点，正好 56pts （update on 17:40） 我当时在妄想什么） 
16:48 完成特殊性质A，+8pts 
17:39 O(n^3) 伪了， 只能做 O(2^n) 暴力，+8pts 
性质B 好像也伪了
总期望得分 8+8=16pts 
*/
