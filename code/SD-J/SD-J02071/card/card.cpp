#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n, m, a, ans[1000000], type[1000000], arr[1000000];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	deque<int> cards;
	for(int i = 1;i <= n;i++){
		cin >> a;
		type[a]++;
		cards.push_front(a);
	}
	for(int i = 1;i <= n;i++){
		arr[i] = cards.front();
		cards.pop_front(); 
	}
	int length = n;
	for(int i = 1;i <= n;i++){
        int num = arr[length];
        ans[num]++;
        int type1[10000] = {0};
        for(int j = 1;j <= length;j++){
        	if(type1[arr[j]] > 0 || arr[j] == num) break; 
        	else{
        		ans[arr[j]]++;
        		type1[arr[j]]++;
			}
		}
		type[arr[length]]--;
		arr[length] = 0;
		length--;
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
	return 0;
}
