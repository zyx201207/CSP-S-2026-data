#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000005
#define i64 long long
int n;
i64 d,x[MAXN];
i64 f[MAXN],g[MAXN];
void solve(){
	cin >>n>>d;
	for (int i = 1;i <= n;i ++) cin >>x[i];
	i64 ans=0;
	for (int i = 1;i < n;i ++){
		fill(f,f+n+1,1e17);
		fill(g,g+n+1,0);
		g[i]=1,f[i]=0;
		int l=i,k=i,sum=1;
		for (int j = i+1;j <= n;j ++){
			while(l<j&&x[l]+d<x[j]){
				if (l<k) sum-=g[l];
				++l;
			}
			if (l==j) break;
			if (k<l){
				k=l;
				sum=g[l];	
			}
			while (k<j&&f[k+1]==f[l]) sum+=g[++k];
			f[j]=f[l]+1;
			g[j]=sum;
			if (g[j]==2) ++ans; 
		}
	}
	cout <<ans<<'\n';
}
void solve12(){
	cin >>n>>d;
	for (int i = 1;i <= n;i ++) cin >>x[i];
	if (n==1){
		cout <<"0\n";
		return;		
	}
	i64 dd=x[2]-x[1],c=d/dd;
	if (c<=1){
		cout <<"0\n";
		return;	
	}
	cout <<max(0ll,n-c-c+1)<<'\n'; 	
}	
int L[MAXN],R[MAXN];
i64 ans;
void dfs(int l,int r,int op,bool is){
	if (l>r) return;
	if (op==1){
		if (l!=r){
			if (L[r-1]<=R[r-1]) dfs(L[r-1],R[r-1],2,L[r]>R[r]);
		}
		if (L[r]<=R[r]) dfs(L[r],R[r],1,true);
	}else{
		ans+=(i64)(r-l+1);
		if (is) dfs(L[r],R[r],2,true);
	}
}
void solve18(){
	cin >>n>>d;
	for (int i = 1;i <= n;i ++) cin >>x[i];
	for (int i = 1;i <= n;i ++) L[i]=R[i]=0;
	for (int i = 1;i <= n;i ++){
		L[i]=R[i-1]+1;
		R[i]=R[i-1];
		while (R[i]<n&&x[i]+d>=x[R[i]+1]) ++R[i];
	}
	ans=0;
	for (int i = 1;i <= n;i ++){
		int l=i+1,r=R[i];
//		cout <<i<<'\n';
		dfs(l,r,1,true);
	}
	cout <<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int c,T;
	cin >>c>>T;
	while (T--){
		if (c<=10) solve();
		else if (c<=12) solve12();
		else if (c<=18) solve18();
	}
	return 0;
}
/*
18 1
7 15
-15 -14 -10 -9 -5 6 11 

6

0 1
7 15
-15 -11 -5 2 10 12 14 

4


d
0 1
5 3
-3 0 2 3 4

0 1
8 20
1 3 5 6 18 22 29 30
0 1
6 12
-10 -6 -2 2 6 10
*/
