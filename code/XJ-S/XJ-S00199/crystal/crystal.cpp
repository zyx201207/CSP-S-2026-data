#include<bits/stdc++.h>
using namespace std;

const int N = 500005;
int n;
long long m;
long long a[N];
int num = 1;
int t = 0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	for(int i=1;i<=n;i++){
		if (a[i] <= a[i+1] && t <= m){
			t += num * (a[i+1] - a[i]);
			if (t > m) break;
			num += 1;
		}
	}
	
	cout << num;
	
	return 0;
}
