#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2*1e6 + 5;
const ll INF = 1e18;
int c,T;
ll n,d;
vector <ll> a;
int same_cnt = 0;
ll mins = INF;
ll turns = 0;

void search(int idx,int idy,ll cnt){
//	printf("search the %d th\n",turns++);
	if (idx == idy && cnt == mins){
//		printf("idx == idy,same_cnt++\n");
		same_cnt++;
		return;
	}
	else if (idx == idy && cnt < mins){
		if (mins == INF){
			mins = cnt;
			same_cnt++;
//			printf("mins change,same_cnt++\n");
			return;
		}
		mins = cnt;
		same_cnt = 1;
		return;
	}
	else if (cnt >= mins || same_cnt > 2){
//		printf("			too long cnt:%d\n",cnt);
		return;
	}
	for (int i = idx+1;i <= idy;i++){
		if (a[i] - a[idx] <= d){
//			printf("from %d to %d now cnt:%d\n",idx,i,cnt+1);
			search(i,idy,cnt+1);
		}
		else {
			return;
		}
	}
//	printf("return for end\n");
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> T;
	while (T--){
		cin >> n >> d;
		a.resize(n);
		ll ans = 0;
		for (int i = 0;i < n;i++){
			cin >> a[i];
		}
		for (int i = 0;i < n;i++){
			for (int j = i+1;j < n;j++){
				same_cnt = 0;
				turns = 0;
				mins = INF;
//				printf("search: %d to %d\n",i,j);
				search(i,j,ll(0));
//				printf("same_cnt:%d\n\n",same_cnt);
				if (same_cnt == 2){
//					printf("ans++\n");
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	
	
	return 0;
}