#include<bits/stdc++.h>
using namespace std;
int n , m;
int a[200005];
bool vis[200005];
int b[200005];
vector<int> x;
void dfs(int id){
	if(id == m + 1){
		int sum = b[0];
		for(int i = 1;i < m;i++){
			sum &= b[i];
		}
		x.push_back(sum);
	}else{
		for(int i = 0;i < n;i++){
			if(!vis[i]){
				b[i] = a[i];
				vis[i] = 1;
				dfs(id + 1);
				vis[i] = 0;
			}
		}
	}
}
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	dfs(1);
	sort(x.begin() , x.end());
	cout << x[x.size() - 1];
	
	return 0;
} 
