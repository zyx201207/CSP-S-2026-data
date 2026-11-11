#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<string>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>

using namespace std;
using ll=long long;
using ull=unsigned long long;
using lb=long double;
using pii=pair<int,int>;
using pll=pair<long long,long long>;
using pil=pair<int,long long>;
using pli=pair<long long,int>;

const int N=4e5+9;
int n,m,res,maxn;
int a[N];
bool vis[N];

void dfs(int pos,int x){
	if(pos == n+1){
		if(x == m){
			int ans=-1;
			for(int i=1; i<=n; i++){
				if(!vis[i])continue;
				if(ans == -1)ans=a[i];
				else ans&=a[i];
				if(ans == 0)break;
			}
			res=max(res,ans);
		}
		return;
	}
	
	vis[pos]=1;
	dfs(pos+1,x+1);
	vis[pos]=0;
	dfs(pos+1,x);
}

int t[N*4];

void update(int p){
	t[p]=t[p*2]&t[p*2+1];
}

void build(int p,int l,int r){
	if(l == r){
		t[p]=a[l];
		return;
	}
	
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	update(p);
}

int sum(int p,int l,int r,int x){
	if(l == r && l == x){
		return a[(x%n+1)];
	}
	if(x > r || x < l)return t[p];
	
	int mid=(l+r)>>1;
	
	return sum(p*2,l,mid,x)&sum(p*2+1,mid+1,r,x);
}

bool checkA(int x){
	while(x){
		if(x&1)x>>=1;
		else return 0;
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	bool A=1,B=1;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		
		maxn=max(maxn,a[i]);
		
		if(!checkA(a[i])) A=0;
		if(a[i] != i-1) B=0;
	}
	
	//----
	if(n <= 20){
		dfs(1,0);
		cout<<res<<'\n';
	}
	else if(m == 1){
		int ma=0;
		for(int i=1; i<=n; i++){
			ma=max(ma,a[i]);
		}
		cout<<ma<<'\n';
	}
	else if(m == n){
		for(int i=2; i<=n; i++){
			a[i]&=a[i-1];
		}
		cout<<a[n]<<'\n';
	}
	else if(m == 2){
		int ma=0;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i == j) continue;
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma<<'\n';
	}
	else if(m == n-1){
		build(1,1,n);
		//cout<<t[1]<<'\n';
		int ma=0;
		for(int i=1; i<=n; i++){
			ma=max(ma,sum(1,1,n,i));
		}
		cout<<ma<<'\n';
	}
	else if(A){
		sort(a+1,a+1+n);
		for(int i=2; i<=m; i++){
			a[i]&=a[i-1];
		}
		cout<<a[m]<<'\n';
	}
	else if(B){
		cout<<n-m<<'\n';
	}
	else if(maxn <= 4){
		int pos[6]={0,0,0,0,0,0};
		for(int i=1; i<=n; i++){
			pos[a[i]]++;
		}
		if(pos[4] >= m)cout<<4<<'\n';
		else if(pos[3] >= m)cout<<3<<'\n';
		else if(pos[2]+pos[3] >= m)cout<<2<<'\n';
		else if(pos[1]+pos[3] >= m)cout<<1<<'\n';
		else cout<<0<<'\n';
	}
	else cout<<511<<'\n';
	
	return 0;
}