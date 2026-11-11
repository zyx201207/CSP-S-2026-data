#include<bits/stdc++.h>
using namespace std;
int n, m;
int t[500005], a[500005], c[500005];
bool f[500005], z;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	if(n == m){
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			c[a[i]] = i; 
		}
		for(int i = 1; i <= m; i++){
			cout << c[i] << " ";
		}
		return 0;
			}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	deque<int> q;
	for(int i = 1; i <= n; i++){
		memset(f, false, sizeof(f));
		for(int j = i; j <= n; j++){
			if(f[a[j]] == true){
								while(!q.empty()&&q.back() != a[j]){
									f[q.back()] = false;
									q.pop_back();
									}	
								}
			else if(f[a[j]] == false){
									f[a[j]] = true;
									q.push_back(a[j]);
									}           
		}
		while(!q.empty()){
			t[q.front()]++;
			q.pop_front();
			}
	}
	for(int i = 1; i <= m; i++){
		cout << t[i] << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
