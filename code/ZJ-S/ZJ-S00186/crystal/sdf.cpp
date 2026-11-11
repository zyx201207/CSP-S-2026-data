#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long a[N],t[N];
int b[N];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	int ma=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]+101]++;
		ma=max(ma,b[a[i]+101]);
	}
	cout<<ma;
	for(int i=1;i<=200;i++){
		cout<<i-100<<' '<<b[i]<<'\n';
	}
	return 0;
}
