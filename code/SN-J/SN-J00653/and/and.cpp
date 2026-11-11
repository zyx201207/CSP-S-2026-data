//姜承宇 西安翱翔中学 SN-J00653
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[2000005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	int sum = a[1];
	for(int i = 2;i<=m;i++){
		if((sum&a[i]) == 0){
			m++;
			continue;
		}
		sum = sum&a[i];
	}
	cout<<sum;
	return 0;
}
