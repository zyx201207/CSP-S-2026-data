#include<bits/stdc++.h>
#define ing long long

using namespace std;

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		int ANS = 0;
		int n;
		long long d;
		cin >> n >> d;
		vector<int> s;
		s.push_back(-1);
		for(int i = 1; i <= n; ++i){
			int c;
			cin >> c;
			s.push_back(c);
		}
		vector<int> ans;
		vector<int> ans2;
		ans2.push_back(0);
		ans2.push_back(0);
		ans2[1] = 0;
		for(int i = 2; i <= n; ++i){
//			ans2 = ans;
			ans2.push_back(0);
			ans2[i] = ans2[i - 1] + 1;
			int cnt = i - 1;
			while((s[i] - s[cnt]) <= d && cnt >= 1){
//				cout << i << " " << cnt << " " << s[i] << " " << s[cnt] << " " << ans2[cnt] << " " << ans2[i] << endl;
//				cout << cnt << " " << i << " ";
//				cout << ans2[cnt] + 1 << " ";
				if(ans2[cnt] + 1 < ans2[i] && ans2[cnt] + 1 >= 1){
					ans2[i] = ans2[cnt] + 1;
				}	
				cnt--;
			}
		}
//		cout << endl;
		ans.push_back(0);
		ans.push_back(0);
		ans[1] = 0;
		for(int i = 2; i <= n; ++i){
			ans.push_back(0);
			ans[i] = ans2[i - 1] + 1;
			int cnt = i - 1;
			int cmp = 0;
			while((s[i] - s[cnt]) <= d && cnt >= 1){
				if(ans[cnt] + 1 <= ans[i] && ans[cnt] + 1 >= 1){
					ans[i] = ans[cnt] + 1;
//					cout << cnt << " " << i << endl;
					if(ans[i] == ans2[i]){
//						cout << "one:" << cnt << " " << i << endl;
						cmp++;
					}
				}
				cnt--;
			}
			if(cmp == 2){
				ANS++; 
			}
//			cout << endl;
		}
//		cout << endl;
		cout << ANS << endl;
	}
	return 0;
}
