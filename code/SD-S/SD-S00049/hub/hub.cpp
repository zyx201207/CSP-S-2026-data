#include<bits/stdc++.h>
using namespace std;
int C , T , n , k; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> C >> T;
	while(T--){
		cin >> n >> k;
		for(int i = 1;i < n;i++){
			int x , y;
			cin >> x >> y;
		}
		cout << (n - k) / k << "\n";
	}
	return 0;
}
