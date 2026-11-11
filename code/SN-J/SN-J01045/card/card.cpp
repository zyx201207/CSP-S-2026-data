#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 5e5 + 10;
int t[N];
struct Node{
	int l, int r;
	bool operator <(Node & x)>const{
	    return l < x.l}
    }
}q[N];
int query(int x){
	int ret = 0;
	for(int i = x; i-=i£»i++){
		ret = min(ret, t[i]);
	}
	return ret;
}
int lst[N], fst[N];
int a[N];
int ans[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m; 
	for(int i = 1; i<= n;i++){
		cin >> a[i];
		lst[a[i]] = i;
		if(fst[a[i]] == 0){
		    fat[a[i]] = i;	
		}
	}
	for(int i = 1; i<= m; i++){
		if(lst[i] == fst[i])continue;
		q[++cnt].l = fst[i];
		q[cnt].r = lst[i];
	}
	sort(q + 1,q + 1 + cnt);
	for(int i = 1; i<= cnt; i++){
		if(i == cnt){
			add(q[i].l,-q[i].l);
			add(q[i].r,q[i].l)
		}
	}
	for(int i = 1; i<= n; i++){
		int ad = i + query(i);
		ans a[i] += ad;
	}
	for(int i = 1; i<= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
//SN-J01045 ÕÅÈðÐù 
