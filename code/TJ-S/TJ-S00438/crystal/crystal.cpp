#include<bits/stdc++.h>
using namespace std;
//tiao zhan na xia S1!!!ovo
#define int long long
const int MAXN = 5e5 + 5;
int n,m,a[MAXN],pre[MAXN],b[MAXN];
struct node{
	int p,cnt;
};
bool cmp(node a,node b){
	return a.cnt > b.cnt;
}
void bl(){
	sort(a + 1,a + n + 1);
	vector<node> nd;
	for(int i = 1;i <= n;++i){
		int tot = 0,tim = 1;
		for(int j = 1;j <= n;++j){
			int dif = a[i] - a[j];
			if(i == j) continue;
			if(dif >= 0){
				tot += dif;
				tim++;	
			}
		}
		//cout << tot << " " << tim << '\n';
		if(tot > m) break;
		nd.push_back((node){tot,tim});
	}
	sort(nd.begin(),nd.end(),cmp);
	cout << nd[0].cnt;
}
void A(){
	for(int i = 2;i <= n;++i){
		pre[i] = pre[i - 1] + a[i - 1];
	}
	int ans = 0;
	for(int i = 1;i <= n;++i){
		if(pre[i] > m) break;
		ans = a[i];
	}
	cout << ans;
}
void B(){
	for(int i = 2;i <= n;++i){
		b[i] = b[i - 1] + (a[i] - a[1]);
	}
	int ans = 0;
	for(int i = 1;i <= n;++i){
		if(b[i] > m) break;
		ans = i;
	}
	cout << ans;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
	}
	if(n <= 5000){
		bl();
		return 0;
	}
	if(a[1] + 1 == a[2]){
		A();
		return 0;
	}
	if(a[2] - a[1] == a[3] - a[2]) B();
	cout << 0;
	return 0;
}
//tiao zhan shi bai...
