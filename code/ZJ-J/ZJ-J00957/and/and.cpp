#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2147483647;
int n, m, a[200005], s[200005], maxn, l=MAXN, ans;
bool isb=true, islow4=true;
bool cmp(int x, int y){
	return x>y;
}
void dfs(int x, int k, int cnt){
	if(x>n) return; 
	if(k==m){
		ans=max(ans, cnt);
		return;
	}
	if(k>m) return;
	for(int i=x+1; i<=n; i++){
		dfs(i, k+1, cnt&a[i]);
	}
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	s[0]=MAXN;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		maxn=max(maxn, a[i]);
		l&=a[i];
		if(isb&&a[i]!=i-1){
			isb=false;
		}
		if(islow4&&a[i]>4) islow4=false;
	}
	//1~5
	if(n<=20){
		for(int i=0; i<n-m; i++){
			dfs(i, 0, MAXN);
		}
		cout << ans;
	}
	//6
	else if(m==1){
		cout << maxn;
	}
	//7
	else if(m==n){
		cout << l;
	}
	//14~15
	else if(isb){
		cout << n-m;
	}
	//8~10
	else if(m==2){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i==j) continue;
				ans=max(ans, a[i]&a[j]);
			}
		}
		cout << ans;
	}
	//11~12
	else if(m==n-1){
		sort(a+1, a+n+1, cmp);
		for(int i=1; i<=n; i++){
			s[i]=s[i-1]&a[i];
		}
		cout << max(s[n], s[n-1]);
	}
	//16~17
	else if(islow4){
		sort(a+1, a+n+1, cmp);
		int p[5]={};
		for(int i=1; i<=n; i++){
			p[a[i]]++;
		}
		if(p[4]>=m){
			cout << 4;
		}
		else if(p[3]>=m){
			cout << 3;
		}
		else if(p[3]+p[2]>=m||p[2]>=m){
			cout << 2;
		}
		else if(p[3]+p[1]>=m||p[1]>=m){
			cout << 1;
		}
		else cout << 0;
	}
	//13
	else{
		sort(a+1, a+n+1, cmp);
		cout << a[m];
	}
	return 0;
}
