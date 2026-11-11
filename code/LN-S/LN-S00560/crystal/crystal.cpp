#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,a[N],m,d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
	long long s=0;
		for(int j=1;j<i;j++){
			s+=a[i]-a[j];
		}
	
	if(s<=m) d=i;
}
	cout<<d;
	return 0;
	}
