#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 100;
int a[N];
struct Node{
	int val,num;//值,数量 
}aa[N];
//还得维护一个前缀和
//d1[i]表示后缀i~cnt的num之和 
//d[i]表示将1~i的全部变成aa[cnt].val的花费
//把l~i全部变成aa[i].val的花费就可以表示为
//(d[l] - d[i+1]) - (sum[l] - sum[i+1]) * (aa[cnt].val - aa[i].val)
int d1[N],d[N];
int n,m;
int cnt = 0;
int check(int mid,int i){
	int l = i-mid;
	//cout << i << ' ' << mid << ' ' <<(d[l] - d[i+1]) - (d1[l] - d1[i+1]) * (aa[cnt].val - aa[i].val) << '\n';
	return (d[l] - d[i+1]) - (d1[l] - d1[i+1]) * (aa[cnt].val - aa[i].val);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//crystal
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; ++i){
		if(a[i] != a[i-1]) aa[++cnt] = {a[i],1};
		else aa[cnt].num++;
	}
	//cout << "A:\n";
	//for(int i = 1; i <= cnt; i++) cout << aa[i].val << ' ' << aa[i].num << '\n';
	for(int i = cnt; i >= 1; --i) d1[i] = d1[i+1] + aa[i].num;
	for(int i = cnt; i >= 1; --i) d[i] = d[i+1] + aa[i].num * (aa[cnt].val - aa[i].val);
	//cout << "D1:\n";
	//for(int i = 1; i <= cnt; i++) cout << d1[i]<< ' ';
	//cout <<'\n';
	//cout << "D:\n";
	//for(int i = 1; i <= cnt; i++) cout << d[i]<< ' ';
	//cout <<'\n';
	//确定变成多少
	int ans = 0;
	for(int i = 1; i <= cnt; ++i){
		if(i == 1){
			ans = max(ans,aa[i].num);
			continue;
		}
		//确定变几个
		int l = 0,r = i-1;
		int xx = 0;
		while(l < r){
			int mid = l+r >>1;
			if(check(mid,i) <= m){
				l = mid+1;
				xx = max(xx,mid);
			}else r = mid-1;
		}
		//ans 表示能变 但i-ans-1可能也有能变的
		if(xx == i-1){//没法扩展
			int num = d1[i-xx] - d1[i+1];
			ans = max(ans,num);
		}else{//尝试扩展
			//扩展i-xx-1
			int num = d1[i-xx] - d1[i+1];
			int used = check(xx,i);
			if(used == 0){//没法扩展
				ans = max(ans,num);
			}else{
				int shen = m - used;
				num += min(shen / (aa[i].val - aa[i-xx-1].val),aa[i-xx-1].num);
				ans = max(ans,num);
			}
		}
		//cout <<i << ' ' <<xx << ' ' << ans << '\n';
	}
	cout << ans;
} 
