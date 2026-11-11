#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
const int N = 2e5 + 10;
int l[N];
char w[N];
int main(){
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)            cin >> l[i] >> w[i];
	int z = 1, y = n;
	while(1){
		if(z >= y)   break; 
		if(w[z] == w[y]){
			if(l[z] > l[y]){
				l[z] = l[z] - l[y];
				y--;
			}
			else if(l[z] < l[y]){
				l[y] = l[y] - l[z];
				z++;
			}
			else{
				z++;
				y--;
			}    
		}
		else{
			if(l[z] > l[y]){
				l[z] = l[z] - l[y];
				ans += l[y];
				y--;
			}
			else if(l[z] < l[y]){
				l[y] = l[y] - l[z];
				ans += l[z];
				z++;
			}
			else{
				ans += l[z];
				z++;
				y--;
			}    
		}
	}
	cout << ans;

	return 0;
}