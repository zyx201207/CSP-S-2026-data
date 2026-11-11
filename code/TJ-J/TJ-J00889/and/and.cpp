#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, idx=1, cnt, ans;
ll arr[200004];
ll bit[35];
vector <int> e[200005];

bool cmp(ll a, ll b){
	return a>b; 
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin>>n>>m;
	
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	
	sort(arr+1, arr+n+1, cmp);
	
	for(int i=30; i>=1; i--){
		for(int j=1; j<=n; j++){
			if((arr[j]>>(i-1))&1){
				bit[i]++;
				e[i].push_back(arr[j]);
			}
		}
		
//		cout<<i<<": "<<bit[i]<<endl;
	}
	
	for(int i=30; i>=1; i--){
		if(bit[i]>=m){
			for(int j=0; j<m; j++){
//				cout<<e[i][j]<<"&";
				
				ans = (!ans ? e[i][j] : ans&e[i][j]);
			}
			
			break;
		}
	}
	
	cout<<ans;
	
	return 0;
} 
