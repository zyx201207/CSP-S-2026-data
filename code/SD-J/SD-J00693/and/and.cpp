#include <bits/stdc++.h>
using namespace std;

int n,m;
const int N = 2e5 + 100;
int a[N];
bool b[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	int pr = 1;
	for(int i = 1;i <= 30;i++)
		pr *= 2;
	int ans = 0;
	while(pr){
		int cnt = 0;
		for(int i = 1;i <= n;i++)
			if(!b[i] && (a[i] & pr)){
				cnt++;
			}
		if(cnt >= m){
			ans+=pr;
			for(int i = 1;i <= n;i++)
				if(!b[i] && (a[i] & pr) == 0)
					b[i] = 1;
		}
		pr /= 2;
	}
	cout << ans;
	return 0; 
}
//Trick||Treat! 
