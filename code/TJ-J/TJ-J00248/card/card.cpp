#include <bits/stdc++.h>

using namespace std;
#define ing long long
int n,m;
int a[500005];
int b[300005];
int maxn=0;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
		if(a[i]<=a[i-1]){
			flag=false;
		}
	}
	if(flag==true){
		for(int i=1;i<=n;i++){
			cout<<i<<' ';
		}
	}
	return 0;
}
