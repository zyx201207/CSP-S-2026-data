#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int a[maxn];
stack<int> s;
int x[maxn];
int cnt[maxn];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++){
		for(int j = i;j <= n;j ++){
			if(s.size() == 0||x[a[j]] == 0){
				s.push(a[j]);
				x[a[j]]++;
			}
			if(x[a[j]]>0){
				while(!s.empty()){
					if(s.top() == a[j]){
						break;
					}
					x[s.top()]--;
					s.pop();
				}
			}
	    }	
		while(!s.empty()){
			s.pop();
		}
		for(int k = 1;k <= m;k ++){
			cnt[k] += x[k];
			x[k] = 0;
		}
	}
	for(int i = 1;i <= m;i ++){
		cout << cnt[i] << " ";
	}
	return 0;
} 
