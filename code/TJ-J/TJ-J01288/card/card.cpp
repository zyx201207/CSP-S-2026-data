#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> a;
vector<long long> f;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	a.push_back(0);
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	
	long long ans=0;
	f.push_back(0);
	f.push_back(0);
	for(int i=2;i<=n;i++){
		f.push_back(0);
		for(int j=m;j>=1;j--){
			f[j]=max(f[j],f[j-1]|a[i]);
		}
	}
	
	cout << f[m] << '\n';
	
	return 0;
}
