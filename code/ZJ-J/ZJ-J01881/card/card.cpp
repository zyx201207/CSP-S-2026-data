#include<bits/stdc++.h>
#define int long long
#define db(x) cout<<#x<<" "<<x<<endl;
using namespace std;
int n,m;
int a[200005];
int b[300004];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(i==a[n])cout<<n;
		else cout<<b[i];
		cout<<' ';
	}
	return 0;
}
/*
4
2 a
3 b
1 c
2 d
*/