#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
struct node{
	int a;
	char ch;
}ly[N];
string str;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> ly[i].a >> ly[i].ch;
	}
	int i = 1,j = n;int ans = 0;
	while(i <= j){
		if(ly[i].a == ly[j].a){
			if(ly[i].ch == ly[j].ch){
				i++;j--;
				continue;
			}
			else{
				ans += ly[j].a;
				i++;j--;
				continue;
			}
		}
		else{
			if(ly[i].a > ly[j].a){
				if(ly[i].ch == ly[j].ch){
					ly[i].a = ly[i].a - ly[j].a;
					j--;
				}
				else{
					ans += ly[j].a;
					ly[i].a = ly[i].a - ly[j].a;
					j--;
				}
			}
			else{
				if(ly[i].ch == ly[j].ch){
					ly[j].a = ly[j].a - ly[i].a;
					i++;
				}
				else{
					ans += ly[i].a;
					ly[j].a = ly[j].a - ly[i].a;
					i++;
				}
			}
		} 
	}
	cout << ans << '\n';
	return 0; 
} 
