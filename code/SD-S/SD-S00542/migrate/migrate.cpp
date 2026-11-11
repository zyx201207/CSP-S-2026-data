#include<bits/stdc++.h>
#define ll long long
#define For(i, j, k) for(int i=j;i<=k;i++)
using namespace std;

const int N = 50005;

int n;
ll m;
ll a[N];
int minn[N<<2], num[N<<2];
struct ANS{
	int minn,num;
};

void update(int u,int L,int R,int k, int x, int op){
	if(L==R){
		minn[u] = x;
		num[u] = op;
		return;
	}
	int M = L+R>>1;
	if(M>=k)update(u<<1,L,M,k,x,op);
	if(M<k)update(u<<1|1,M+1,R,k,x,op);
	minn[u] = min(minn[u<<1],minn[u<<1|1]);
	if(minn[u<<1]<minn[u<<1|1])num[u] = num[u<<1];
	else if(minn[u<<1]>minn[u<<1|1])num[u] = num[u<<1|1];
	else num[u] = num[u<<1]+num[u<<1|1];
}

ANS calc(ANS a, ANS b){
	if(a.minn<b.minn){
		return a;
	}else if(a.minn>b.minn){
		return b;
	}else{
		return {a.minn,a.num+b.num};
	}
}

ANS query(int u,int L,int R,int l,int r){
	if(L>=l&&R<=r){
		return {minn[u],num[u]};
	}
	int M = L+R>>1;
	ANS ans = {0x3f3f3f3f, 0};
	if(M>=l){
		ans = calc(ans, query(u<<1,L,M,l,r));
	}
	if(M<r)ans = calc(ans ,query(u<<1|1,M+1,R,l,r));
	return ans;
}

void solve(){
	cin >> n >> m;
	For(i, 1, n) cin >> a[i];
	int cnt = 0;
	For(i, 1, n-1){
		memset(num, 0, sizeof num);
		memset(minn, 0x3f, sizeof minn);
		update(1,1,n,i,0,1);
//		For(k, 1, n)cout << query(1,1,n,k,k).minn << " ";
//			cout << "\n";
//		cout << minn[1] << "\n";
		For(j, i+1, n){
			int id = lower_bound(a+1,a+n+1,a[j]-m)-a;
			if(id>=j)break;
			ANS ans = query(1,1,n,id,j-1);
			if(ans.num==2)cnt++;
			update(1,1,n,j,ans.minn+1,ans.num);
//			For(k, 1, n)cout << query(1,1,n,k,k).num << " ";
//			cout << "\n";
		}
	}
	cout << cnt << "\n";
}

/*
0 1
5 2
1 2 3 4 5
*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	int c, t;
	cin >> c >> t;
	while(t--)solve();
	return 0;
}
