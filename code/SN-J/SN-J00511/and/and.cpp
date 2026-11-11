#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		int cnt=a[i];
		for(int j=1;j<m;j++){
			int t=i+j;
			if(t>n){
				t%=n;
			}
			cnt=cnt&a[t];
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
}
