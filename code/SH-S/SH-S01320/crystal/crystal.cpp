#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 20;
long long a[N];
long long cha[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int len = n-1;
	for(int i=1;i<=n-1;i++){
		cha[i] = a[i+1] - a[i];
	}
	int mx = 1;
	for(int i=1;i<=len;i++){
		for(int j=1;j<=len;j++){
			int cnt = 0;
			for(int k=i;k<=j;k++){
				cnt += cha[k];
			}
			if(m >= cnt){
				mx = max(mx,j-i+1);
			}
		}
	}
	cout << mx+1 << endl;
	return 0;
}
