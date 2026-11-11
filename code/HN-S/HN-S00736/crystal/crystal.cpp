#include <bits/stdc++.h>
#define int long long
#define ll long long
#define f(i,l,r) for(int i =l;i<=r;i++)
#define fe(i,l,r) for(int i = l;i>=r;i--)
#define endl '\n' 

using namespace std; 

const int N = 1e6 + 5;
const int M = 1e6 + 5;

int n,m;
int v[N],v_add[N];

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >>m;
	f(i,1,n)cin >>v[i];
	sort(v+1,v+n+1);
	f(i,1,n)v_add[i] = v_add[i-1] + v[i];//cout <<v_add[i] << ' ';
//	cout <<endl;
	int ans = 0;
	
	f(i,1,n){
		int L = 1,R = i,mid;
		while(L < R){
			mid = L + R >>1;
//			cout << mid <<' ' << i << ' ' <<v[i] * (i-mid) << ' ' << (v_add[i-1] - v_add[mid-1]) <<endl;
			if(v[i] * (i-mid) - (v_add[i-1] - v_add[mid-1]) <= m){
				R = mid;
			}else {
				L = mid +1;
			}
		}
//		if(L == 5000)cout << i << ' ' << L << ' ' <<check(i,L)<<endl;
//		cout <<L << ' ' <<R <<endl;
		ans = max(i - L+1,ans);
	}
//	cout <<v[2500] * 2499 - v_add[2499] << ' ' << v_add[5000] - v_add[2500] - v[2500] * 2500 << ' ' <<v[2500]  << ' ' << v[2500] * 2499 - v_add[2499] + v_add[5000] - v_add[2500] - v[2500] * 2500<< endl;
	cout << ans <<endl;
	return 0;
}
/*
int v[N];

int head[N],to[M],nxt[M];
int edgetot = 2;
void addedge(int a,int b,int c) {
	++edgetot;
	nxt[edgetot] = head[a];
	to[edgetot] = b;
}
*/
