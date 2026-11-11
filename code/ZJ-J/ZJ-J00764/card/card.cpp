#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n,m,a[N],cnt[N];
vector<int> pos[N];
int find(int t){
	for(int it : pos[a[t]]){
		if(it > t){
			return it;
		}
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		pos[a[i]].push_back(i);
	}
	for(int i = 1;i <= n;i++){
		int now = i,prv = i;
		while(now <= n){
			int p = find(now);
			if(p != -1){
				for(int j = prv;j < now;j++){
					cnt[a[j]]++;
				}
				prv = now = p;
			}else{
				now++;
			}
		}
		for(int j = prv;j <= n;j++){
			cnt[a[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}