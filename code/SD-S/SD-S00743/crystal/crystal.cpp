#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,cnt,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cnt=1;
	for(int i=2;i<=n;i++){
		if(a[i-1]!=a[i]){
			if(a[i]-a[i-1]<=m){
				m-=cnt*(a[i]-a[i-1]);
				cnt++;
			}
		}
		else{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
