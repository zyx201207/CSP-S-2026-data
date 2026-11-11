#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int bg, ed;
int cnt;
int num;
int n, m, a[maxn];
int count(int l[]){
	int tmp = 1, cnt = 1;
	for(int i = 0; i < n - 1; i++){
		if(l[i] == l[i + 1]){
			tmp++;
			if(tmp >= cnt){
				cnt = tmp;
				ed = i + 1;
				bg = i + 2 - cnt;
			}
		}else{
			tmp = 1;
		}
	}
	return cnt;
}
void dfs(int m, int bg, int ed, int tmp){
	//cout<<"m: "<<m<<" num: "<<num<<" bg: "<<bg<<" a[bg]: "<<a[bg]<<" ed: "<<ed<<" a[ed]: "<<a[ed]<<" tmp: "<<tmp<<endl;
	if(bg != 0){
		int cha = num - a[bg - 1];
		if(m < tmp && m < cha){
			return;
		}
		if(cha <= m){
			tmp++;
			cnt = max(cnt, tmp);
			dfs(m - cha, bg - 1, ed, tmp);
			tmp--;
		}
	}
	if(ed < n - 1 && tmp * (a[ed + 1] - num) <= m ){
		int c = (a[ed + 1] - num);
		num += c;
		tmp++;
		cnt = max(cnt, tmp);
		dfs(m - (tmp - 1) * c , bg, ed + 1, tmp);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
	if(n <= 5000){
		sort(a, a + n);
		cnt = count(a);
		num = a[ed];
		/*while(m){
			a[0]++;
			sort(a, a + n);
			cnt = max(count(a), cnt);
			m--;
		}*/
		dfs(m, bg, ed, cnt);
		cout<<cnt;
	}
	else{
		int cha = a[1]- a[0];
		int t = cha;
		while(m>=t){
		m-=t;
		t += cha;
		}	
		cout<<t / cha;
	}
	return 0;
}
