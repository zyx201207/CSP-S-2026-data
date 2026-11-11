#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=m;i++){
    	int sum=0;
    	for(int j=1;j<=m;j++){
    		sum=sum+a[i*j+1];
		}
	}
	cout<<ans;
	return 0;
}

