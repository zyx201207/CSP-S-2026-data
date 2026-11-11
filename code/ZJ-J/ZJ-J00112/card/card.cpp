#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 1000;
const int M = 3e5 + 1000;
int f[N],nxt[N],wbw[M];
struct node{
	int l,r;
}Seg[N];
int n,m,cnt;
int a[N];
int ctt[N];
int ans[M];
int pre[N];
bool vis[N];
int b[N];
vector<int> g;
bool cmp(node x,node y){
	return x.l < y.l;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(wbw[a[i]] == 0){
			wbw[a[i]] = i;
			continue;
		}
		cnt ++;
		Seg[cnt].l = wbw[a[i]];
		Seg[cnt].r = i - 1;
		wbw[a[i]] = i;
	//	cout <<cnt <<" "<< Seg[cnt].l <<" " << Seg[cnt].r<<"\n";
		b[Seg[cnt].l] ++;
		b[Seg[cnt].r + 1] --;
	}
//	cout << cnt <<"\n";
	int o;
//	cout<<ans[1]<<"\n";
	sort(Seg + 1, Seg + cnt + 1, cmp);
	for(int i = 1;i <= n;i++){
		pre[i] = pre[i - 1] + b[i];
		if(pre[i] == 0){
			ans[a[i]] += i ;
		}	
		else{
			int l = 1,r= cnt;
			while(l + 1< r){
				int mid = l + r >> 1;
				if(Seg[mid].l <= i) l =  mid;
				else r = mid;
			}
			int  p;
			if(Seg[r].l <= i) p = r;
			else if(Seg[l].l <= i) p = l;
			while(p >= 1 && Seg[p].r < i) p--;
			ans[a[i]]  += i - Seg[p].l;
		}
	}
//	for(int i = 1;i <= m;i++){
//		cout << ans[i] <<" ";
//	}
	ctt[1] = Seg[1].l;
	for(int i = 2;i <= cnt;i++){
		ctt[i] = Seg[i].l - Seg[i - 1].l;
	}
	for(int i = 1;i <= cnt;i++){
		if(vis[i]) continue;
		g.clear();
		g.push_back(i);
		int t = i;
		while(t < cnt){
			int j = t + 1;
			while(j <= cnt && Seg[j].l <= Seg[t].r) ++j;
			if(j > cnt) break;
			vis[j] = true;
			for(int p = Seg[t].r + 1;p <= Seg[j].l - 1;p++){
				for(int v : g){
					if(pre[p] != 0){
					//	cout << p <<" " <<Seg[v].l <<" "<<Seg[v].r <<" " << ctt[v] <<"\n";
						ans[a[p]] += ctt[v];
					}
				}
			}
			g.push_back(j);
			t = j;
		}
		
		for(int p = Seg[t].r + 1;p <= n;p++){
			for(int v : g){
				if(pre[p] != 0)ans[a[p]] += ctt[v];
			}
		}
		
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] <<" ";
	}
	return 0;
}
