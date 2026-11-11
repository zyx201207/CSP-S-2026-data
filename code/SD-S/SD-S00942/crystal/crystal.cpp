#include<bits/stdc++.h>
using namespace std;
int n;long long m;
int arr[500050];
long long s_fc[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i = 1;i<=n;i++){
		s_fc[i] = (i-1)*(arr[i]-arr[i-1])+s_fc[i-1];
		if(s_fc[i]>m){
			cout << i-1;
			return 0;
		}
	}
	cout << n << endl;
	return 0;
}

